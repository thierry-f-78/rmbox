#ifndef FIRE_H__
#define FIRE_H__

#include "SDL.h"

/**
 * G�n�re un foyer gris sur la surface donn�e, dans les limites de
 * rect, en fonction des param�tres intensity, vivacity et r�sistance.
 * Attention: la surface doit �tre verrouill�e!
 */
void fireRoot(SDL_Surface * surface, SDL_Rect * rect, Uint8 intensity, Uint8 vivacity, Uint8 resistance);

/**
 * Applique l'effet de feu sur la surface donn�e, dans les limites de
 * rect.  Attention: la surface doit �tre verrouill�e!
 */
void fire(SDL_Surface * surface, SDL_Rect * rect);


#endif
