/*
 * Copyright 2011-2019 Thierry FOURNIER
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version
 * 2 of the License.
 *
 */
#include <SDL/SDL.h>
#include <png.h>

SDL_Surface *SDL_LoadPNG(char *filename) {
	SDL_Surface *sdl_png;
	FILE *fp;
	png_byte magic[8];
	png_structp png_ptr;
	png_infop info_ptr;
	int bit_depth;
	int color_type;
	int width, height;
	png_bytep *row_pointers;
	int i;
	unsigned char color;
	int pitch;

	// open image file
	fp = fopen (filename, "rb");
	if (!fp) {
		fprintf (stderr, "error: couldn't open \"%s\"!\n", filename);
		return NULL;
	}

	// read magic number
	fread (magic, 1, sizeof(magic), fp);

	// check for valid magic number
	if (!png_check_sig (magic, sizeof (magic))) {
		fprintf (stderr, "error: \"%s\" is not a valid PNG image!\n",
		         filename);
		fclose (fp);
		return NULL;
	}

	// create a png read struct
	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr) {
		fclose (fp);
		return NULL;
	}

	// create a png info struct
	info_ptr = png_create_info_struct (png_ptr);
	if (!info_ptr) {
		fclose (fp);
		png_destroy_read_struct (&png_ptr, NULL, NULL);
		return NULL;
	}

	// initialize the setjmp for returning properly after a libpng error occured
	if (setjmp (png_jmpbuf (png_ptr))) {
		fclose (fp);
		png_destroy_read_struct (&png_ptr, &info_ptr, NULL);
		/*
		if (texinfo) {
			if (texinfo->texels)
				free (texinfo->texels);

			free (texinfo);
		}
		*/

		return NULL;
	}

	// setup libpng for using standard C fread() function with our FILE pointer
	png_init_io (png_ptr, fp);

	// tell libpng that we have already read the magic number
	png_set_sig_bytes (png_ptr, sizeof (magic));

	// read png info 
	png_read_info (png_ptr, info_ptr);

	// get some usefull information from header
	bit_depth = png_get_bit_depth (png_ptr, info_ptr);
	color_type = png_get_color_type (png_ptr, info_ptr);

	// convert index color images to RGB images
	if (color_type == PNG_COLOR_TYPE_PALETTE)
		png_set_palette_to_rgb (png_ptr);

	// convert 1-2-4 bits grayscale images to 8 bits grayscale.
	if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
		png_set_gray_1_2_4_to_8 (png_ptr);

	if (png_get_valid (png_ptr, info_ptr, PNG_INFO_tRNS))
		png_set_tRNS_to_alpha (png_ptr);

	if (bit_depth == 16)
		png_set_strip_16 (png_ptr);
	else if (bit_depth < 8)
		png_set_packing (png_ptr);

	// update info structure to apply transformations
	png_read_update_info (png_ptr, info_ptr);

	// retrieve updated information 
	png_get_IHDR (png_ptr, info_ptr,
	              (png_uint_32*)(&width),
	              (png_uint_32*)(&height),
	              &bit_depth, &color_type,
	              NULL, NULL, NULL);

/*
	switch (color_type) {

		case PNG_COLOR_TYPE_GRAY:
		texinfo->format = GL_LUMINANCE;
		texinfo->internalFormat = 1;
		break;

		case PNG_COLOR_TYPE_GRAY_ALPHA:
		texinfo->format = GL_LUMINANCE_ALPHA;
		texinfo->internalFormat = 2;
		break;

		case PNG_COLOR_TYPE_RGB:
		texinfo->format = GL_RGB;
		texinfo->internalFormat = 3;
		break;

		case PNG_COLOR_TYPE_RGB_ALPHA:
		texinfo->format = GL_RGBA;
		texinfo->internalFormat = 4;
		break;

		default:
		break;
	}
*/

	// we can now allocate memory for storing pixel data
	if (color_type == PNG_COLOR_TYPE_RGB_ALPHA) {
		sdl_png = SDL_CreateRGBSurface(SDL_SRCALPHA, width, height, 32,
		                               0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
		pitch = 4 * width;
	} else if (color_type == PNG_COLOR_TYPE_RGB) {
		sdl_png = SDL_CreateRGBSurface(0, width, height, 32,
		                               0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
		pitch = 3 * width;
	}

	// setup a pointer array.  Each one points at the begening of a row.
	row_pointers = (png_bytep *)malloc(sizeof(png_bytep) * height);

	for (i=0; i<height; i++)
		row_pointers[i] = &((png_byte *)sdl_png->pixels)[pitch*i];

	// read pixel data using row pointers
	png_read_image(png_ptr, row_pointers);

	// we don't need row pointers anymore
	free(row_pointers);

	// finish decompression and release memory
	png_read_end (png_ptr, NULL);
	png_destroy_read_struct (&png_ptr, &info_ptr, NULL);

	// inverse bits
	if (color_type == PNG_COLOR_TYPE_RGB_ALPHA) {
		for (i=0; i<sdl_png->pitch*height; i+=sdl_png->format->BytesPerPixel) {
			// png -> sdl
			//  R      A
			//  G      B
			//  B      G
			//  A      R
			color = ((unsigned char *)sdl_png->pixels)[i];
			((unsigned char *)sdl_png->pixels)[i] = ((unsigned char *)sdl_png->pixels)[i+3];
			((unsigned char *)sdl_png->pixels)[i+3] = color;
			color = ((unsigned char *)sdl_png->pixels)[i+1];
			((unsigned char *)sdl_png->pixels)[i+1] = ((unsigned char *)sdl_png->pixels)[i+2];
			((unsigned char *)sdl_png->pixels)[i+2] = color;
		}
	} else if (color_type == PNG_COLOR_TYPE_RGB) {
		for (i=(width*height)-1; i>=0; i--) {
			int pos_32 = i*sdl_png->format->BytesPerPixel;
			int pos_24 = i*3;
			// png -> sdl
			//  R      A
			//  G      B
			//  B      G
			//         R
			// red
			((unsigned char *)sdl_png->pixels)[pos_32+3] = ((unsigned char *)sdl_png->pixels)[pos_24+0];
			// green
			((unsigned char *)sdl_png->pixels)[pos_32+2] = ((unsigned char *)sdl_png->pixels)[pos_24+1];
			// blue
			((unsigned char *)sdl_png->pixels)[pos_32+1] = ((unsigned char *)sdl_png->pixels)[pos_24+2];
			// alpha
			((unsigned char *)sdl_png->pixels)[pos_32+0] = 0xff;
		}
	}

	fclose (fp);

	return sdl_png;
}
