/*
 * Copyright 2011-2019 Thierry FOURNIER
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version
 * 2 of the License.
 *
 */
#include <string.h>

#include "structs.h"

/* colle l'image dans la buffer pret a sortir
 * x, y, src_x, src_y, width et height DOIVENT
 *   etre POSITIFS, aucun controle n'est fait !
 * @param img: image a coller
 * @param x, y: coordonée ou coller l'image
 * @param src_x, y: coordonnées de l'image source a partir de 
 *                  laquelle coller
 * @param width, height: longueur, hauteur a coller
 */
void put_image(struct vimg * aff,
               struct vimg * img,
               int x, int y,
               int src_x, int src_y,
               int width, int height){
	int ba;  // pointe sur le premier octet de aff remplir par le
	         // premier octet de img
	int bi;  // pointe sur le premier octet de img a copier
	         // dans le premier octet de aff
	int sa;  // longueur a sauter pour revenir au debut de la
	         // zone a coller
	int si;  // longueur a sauter pour revenir au debut de la
	         // zone a copier
	int lgn; // longueur d'une ligne a copier
	int end; // nombre de lignes a copier
	int i, j;
	
	// printf("i\n");
	
	// controle d'affichage
	if(x >= (int)aff->width ||
	   y >= (int)aff->height ||
	   ( x + (int)width ) < 0 ||
		( y + (int)height ) < 0){
		return;
	}
	
	// calcul du premier pixel de aff
	ba = (x<0?0:x) + ( (y<0?0:y) * aff->width );

	// calcul du premier pixel de img
	bi = (x<0?src_x-x:src_x) + ( (y<0?src_y-y:src_y) * img->width );
	
	// calcul de la longueur de la ligne a copier
	if(width + x >= aff->width){
		lgn = aff->width - x - 1;
	} else {
		lgn = width;
	}
	if(x < 0){
		lgn += x;
	}

	// calcul du nombre de lignes a copier
	if(height + y >= aff->height){
		end = aff->height - y - 1;
	} else {
		end = height;
	}
	if(y < 0){
		end += y;
	}

	// calcul du nombre de pixel a sauter pour revenir en debut de ligne
	// pour affx
	sa = aff->width - lgn;

	// pour img
	si = img->width - lgn;
	
	// copie
	i = 0;
	while(i < end){
		memcpy(&aff->pixel_data[ba], &img->pixel_data[bi], 4 * lgn);
		ba += (sa + lgn);
		bi += (si + lgn);
		i ++;
	}
	//printf("o\n");
}

/* applique un masque de transparence a une image
 * OxOO: tranparent
 * 0xff: opaque
 *
 * @param img: image a modifier
 * @param out: image de reception
 *             peut etre identique a la source
 *             doit pouvoir recevoir l'image
 * @param alpha: valeur alpha
 */
void set_alpha(struct vimg * img,
               struct vimg * out,
               unsigned char alpha){
	int i;
	int a;

	out->width = img->width;
	out->height = img->height;
	for(i = 0; i < img->width * img->height; i++){
		a = img->pixel_data[i].a + alpha - 255;
		if(a < 0) a = 0;
		else if(a > 255) a = 255;
		out->pixel_data[i].a = a;
		out->pixel_data[i].r = img->pixel_data[i].r;
		out->pixel_data[i].g = img->pixel_data[i].g;
		out->pixel_data[i].b = img->pixel_data[i].b;
	}
}

/* colle l'image dans la buffer pret a sortir
 * x, y, src_x, src_y, width et height DOIVENT
 *   etre POSITIFS, aucun controle n'est fait !
 *
 * @param img: image a coller
 * @param x, y: coordonée ou coller l'image
 * @param src_x, y: coordonnées de l'image source a partir de 
 *                  laquelle coller
 * @param width, height: longueur, hauteur a coller
 */
void put_image_alpha(struct vimg * aff,
                     struct vimg * img,
                     int x, int y,
                     int src_x, int src_y,
                     int width, int height){
	int ba;  // pointe sur le premier octet de aff remplir par le
	         // premier octet de img
	int bi;  // pointe sur le premier octet de img a copier
	         // dans le premier octet de aff
	int sa;  // longueur a sauter pour revenir au debut de la
	         // zone a coller
	int si;  // longueur a sauter pour revenir au debut de la
	         
				// zone a copier
	int lgn; // longueur d'une ligne a copier
	int end; // nombre de lignes a copier
	int i, j;
	unsigned char tr;
	int tmp;
	
	// printf("i\n");
	
	// controle d'affichage
	if(x >= (int)aff->width ||
	   y >= (int)aff->height ||
	   ( x + (int)width ) < 0 ||
		( y + (int)height ) < 0){
		return;
	}
	
	// calcul du premier pixel de aff
	ba = (x<0?0:x) + ( (y<0?0:y) * aff->width );

	// calcul du premier pixel de img
	bi = (x<0?src_x-x:src_x) + ( (y<0?src_y-y:src_y) * img->width );
	
	// calcul de la longueur de la ligne a copier
	if(width + x >= aff->width){
		lgn = aff->width - x - 1;
	} else {
		lgn = width;
	}
	if(x < 0){
		lgn += x;
	}

	// calcul du nombre de lignes a copier
	if(height + y >= aff->height){
		end = aff->height - y - 1;
	} else {
		end = height;
	}
	if(y < 0){
		end += y;
	}

	// calcul du nombre de pixel a sauter pour revenir en debut de ligne
	// pour affx
	sa = aff->width - lgn;

	// pour img
	si = img->width - lgn;
	
	// OxOO: tranparent
	// 0xff: opaque

	// copie
	i = 0;
	while(i < end){
		// copie
		j=0;
		while(j < lgn){
			//tr = 0xff - img->pixel_data[bi].a;
			#define RF img->pixel_data[bi].a / 0xff
			#define RB (0xff - img->pixel_data[bi].a) / 0xff
			
			// F: foreground, B=background
			//Fa * Frgb + (1 - Fa) * Brgb
			
			tmp = img->pixel_data[bi].r * RF +
			      aff->pixel_data[ba].r * RB;
			//tmp = affx.pixel_data[ba].r * 
			//      tr / 0xff + img->pixel_data[bi].r;
			if(tmp < 0){
				aff->pixel_data[ba].r = 0;
			} else if(tmp > 0xff){
				aff->pixel_data[ba].r = 0xff;
			} else {
				aff->pixel_data[ba].r = tmp;
			}

			tmp = img->pixel_data[bi].b * RF +
			      aff->pixel_data[ba].b * RB;
			//tmp = affx.pixel_data[ba].b * 
		   //      tr / 0xff + img->pixel_data[bi].b;
			if(tmp < 0){
				aff->pixel_data[ba].b = 0;
			} else if(tmp > 0xff){
				aff->pixel_data[ba].b = 0xff;
			} else {
				aff->pixel_data[ba].b = tmp;
			}

			tmp = img->pixel_data[bi].g * RF +
			      aff->pixel_data[ba].g * RB;
			//tmp = affx.pixel_data[ba].g * 
			//      tr / 0xff + img->pixel_data[bi].g;
			if(tmp < 0){
				aff->pixel_data[ba].g = 0;
			} else if(tmp > 0xff){
				aff->pixel_data[ba].g = 0xff;
			} else {
				aff->pixel_data[ba].g = tmp;
			}

			ba++;
			bi++;
			j++;
		}
		ba += sa;
		bi += si;
		i ++;
	}
}

