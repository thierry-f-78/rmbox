#include <stdlib.h>
#include "fire.h"

/* Retourne les valeurs sur 8 bits des composantes rouges, vertes et
   bleues par rapport au format donné */
#define REDVALUE(format, pixel) (Uint8) (((pixel & format->Rmask) << format->Rloss) >> format->Rshift)
#define GREENVALUE(format, pixel) (Uint8) (((pixel & format->Gmask) << format->Gloss) >> format->Gshift)
#define BLUEVALUE(format, pixel) (Uint8) (((pixel & format->Bmask) << format->Bloss) >> format->Bshift)

/* Crée les masques correspondants pour les composantes de couleur
   données sur 8 bits */
#define REDMASK(format, red) (Uint32) (((red << format->Rshift) >> format->Rloss) & format->Rmask)
#define GREENMASK(format, green) (Uint32) (((green << format->Gshift) >> format->Gloss) & format->Gmask)
#define BLUEMASK(format, blue) (Uint32) (((blue << format->Bshift) >> format->Bloss) & format->Bmask)

/* Retourne la valeur d'un pixel selon ses 3 composantes de couleur,
   données sur 8 bits */
#define MAKEPIXEL(format, red, green, blue) (Uint32) (REDMASK(format, red) | GREENMASK(format, green) | BLUEMASK(format, blue))

/* Lit et affecte un pixel à partir d'un pointeur */
#define READPIXEL(pointer, pixel) { pixel = *(Uint16 *)(pointer) + (*(Uint8 *)((pointer) + 2) << 16); }
#define STOREPIXEL(pointer, pixel) { *(Uint16 *)(pointer) = (Uint16)(pixel); *(Uint8 *)((pointer) + 2) = (Uint8)((pixel) >> 16) & 0xff; }

/* Effet de foyer */
void fireRoot(SDL_Surface * surface, SDL_Rect * rect, Uint8 intensity, Uint8 vivacity, Uint8 resistance) {
  Uint32 i, j;
  
  /* Pour chaque ligne du foyer, la vivacité détermine combien de
     pixels mettre à jour */
  for (j = rect->y; j < rect->y + rect->h; j++)
    for (i = 0; i < vivacity; i++) {
      /* Déterminer la valeur de chaque composante en fonction de
	 l'intensité - elles auront les mêmes valeurs, ce qui nous
	 fournira un gris */
      Uint8 color = (intensity + (rand() % (256 - intensity)));
      /* Choisir une position au hasard */
      Uint32 position = (rand() % rect->w) + rect->x;

      /* Et y affecter le pixel */
      STOREPIXEL(surface->pixels + j * surface->pitch + position * surface->format->BytesPerPixel, 
		 MAKEPIXEL(surface->format, color, color, color));
    }

  /* Même chose avec la résistance - on éteint aléatoirement des
     pixels */
  for (j = rect->y; j < rect->y + rect->h; j++)
    for (i = 0; i < resistance; i++) {
      Uint32 position = (rand() % rect->w) + rect->x;

      STOREPIXEL(surface->pixels + j * surface->pitch + (position * surface->format->BytesPerPixel), 0);
    }
}

/* Effet de feu */
void fire(SDL_Surface * surface, SDL_Rect * rect) {
  Uint32 i, j;

  /* Chaque pixel de la zone doit être mis à jour */
  for (j = rect->y; j < rect->y + rect->h; j++)
    for (i = rect->x; i < rect->x + rect->w; i++) {
      /* Pointeur vers le pixel courant */
      void * curpixel;
      /* Nouvelle valeur du pixel courant */
      Uint32 pixvalue = 0;
      /* Addition des valeurs des composantes rouges, vertes et bleues
	 des pixels adjacents au pixel courant */
      Uint16 red = 0, green = 0, blue = 0;

      /* Le pixel à mettre à jour */
      curpixel = surface->pixels + (surface->pitch * j) + (i * surface->format->BytesPerPixel);
      
      /* Addition des composantes des 4 pixels adjacents */
      /* Inférieur gauche */
      if (i > 0) {
	READPIXEL(curpixel + surface->pitch - surface->format->BytesPerPixel, pixvalue);
	red += REDVALUE(surface->format, pixvalue);
	green += GREENVALUE(surface->format, pixvalue);
	blue += BLUEVALUE(surface->format, pixvalue);
      }

      /* Inférieur */
      READPIXEL(curpixel + surface->pitch, pixvalue);
      red += REDVALUE(surface->format, pixvalue);
      green += GREENVALUE(surface->format, pixvalue);
      blue += BLUEVALUE(surface->format, pixvalue);

      /* Deux lignes en dessous */
      READPIXEL(curpixel + surface->pitch * 2, pixvalue);
      red += REDVALUE(surface->format, pixvalue);
      green += GREENVALUE(surface->format, pixvalue);
      blue += BLUEVALUE(surface->format, pixvalue);

      /* Inférieur droit */
      if (i < surface->w - 1) {
	READPIXEL(curpixel + surface->pitch + surface->format->BytesPerPixel, pixvalue);
	red += REDVALUE(surface->format, pixvalue);
	green += GREENVALUE(surface->format, pixvalue);
	blue += BLUEVALUE(surface->format, pixvalue);
      }
      
      /* Altération des composantes afin d'obtenir la teinte de la
	 flamme */
      if (red > 2) red -= 2; else red = 0;
      if (green > 5) green -= 5; else green = 0;
      if (blue > 150) blue -= 150; else blue = 0;

      /* Division par quatre de l'addition des composantes */
      red /= 4; green /= 4; blue /= 4;

      /* Affectation de la nouvelle valeur du pixel */
      STOREPIXEL(curpixel, MAKEPIXEL(surface->format, red, green, blue));
    }
}
