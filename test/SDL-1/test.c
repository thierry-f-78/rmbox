#include <stdio.h>
#include <unistd.h>
#include <SDL/SDL.h>

void putPixel(SDL_Surface * surface, Uint16 x, Uint16 y, Uint32 color)
{
    /* Nombre de bits par pixels de la surface d'écran */
    Uint8 bpp = surface->format->BytesPerPixel;
    /* Pointeur vers le pixel à remplacer (pitch correspond à la taille 
       d'une ligne d'écran, c'est à dire (longueur * bitsParPixel) 
       pour la plupart des cas) */
    Uint8 * p = ((Uint8 *)surface->pixels) + y * surface->pitch + x * bpp;

    switch(bpp)
    {
	  case 1:
		*p = (Uint8) color;
		break;
        case 2:
            *(Uint16 *)p = (Uint16) color;
            break;
        case 3:
            if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
            {
                *(Uint16 *)p = ((color >> 8) & 0xff00) | ((color >> 8) & 0xff);
                *(p + 2) = color & 0xff;
            }
            else
            {
                *(Uint16 *)p = color & 0xffff;
                *(p + 2) = ((color >> 16) & 0xff) ;
            }
            break;
        case 4:
            *(Uint32 *)p = color;
            break;
    }
}

int main(int argc, char * argv[])
{
    SDL_Surface * screen;
    SDL_Surface * image, * tmp;
    SDL_Rect blitrect = {0, 0, 0, 0};
    int i, j;

    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        printf("Erreur lors de l'initialisation de SDL: %s\n", SDL_GetError());
        return 1;
    }
#define SDL_VIDEO_FLAGS (SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_ANYFORMAT)

    screen = SDL_SetVideoMode(640, 480, 24, 
                              SDL_VIDEO_FLAGS);

    printf("Mode vidéo: %dx%dx%d\n", screen->w, screen->h, 
           screen->format->BitsPerPixel);
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0x00, 0x00, 0xff));
    SDL_LockSurface(screen);
    for (j = 0; j < screen->h; j++)
        for (i = j % 2; i < screen->w; i+=2)
            putPixel(screen, i, j, SDL_MapRGB(screen->format, 0xff, 0xff, 0xff));
    SDL_UnlockSurface(screen);
    tmp = SDL_LoadBMP("image.bmp");
    image = SDL_DisplayFormat(tmp);
    SDL_FreeSurface(tmp);

    /* Affichage sans masque ni alpha */
    blitrect.x = (screen->w - (image->w * 4)) / 2;
    blitrect.y = (screen->h - image->h) / 2;
    SDL_BlitSurface(image, NULL, screen, &blitrect);

    blitrect.x += image->w;
    /* Sélection de la couleur 0xff00ff comme masque */
    SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, 0xff, 0x00, 0xff));
    SDL_BlitSurface(image, NULL, screen, &blitrect);

    blitrect.x += image->w;
    /* Suppression du masque de l'image */
    SDL_SetColorKey(image, 0, 0);
    /* Alpha mis à 128 (soit 50% de transparence) */
    SDL_SetAlpha(image, SDL_SRCALPHA, 128);
    SDL_BlitSurface(image, NULL, screen, &blitrect);

    blitrect.x += image->w;
    /* Sélection de la couleur 0xff00ff comme masque */
    SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, 0xff, 0x00, 0xff));
    SDL_BlitSurface(image, NULL, screen, &blitrect);
    SDL_Flip(screen);
    sleep(5);
    SDL_Quit();
    return 0;
}
