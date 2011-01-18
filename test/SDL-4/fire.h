#ifndef FIRE_H__
#define FIRE_H__

#include "SDL.h"

/**
 * Génère un foyer gris sur la surface donnée, dans les limites de
 * rect, en fonction des paramètres intensity, vivacity et résistance.
 * Attention: la surface doit être verrouillée!
 */
void fireRoot(SDL_Surface * surface, SDL_Rect * rect, Uint8 intensity, Uint8 vivacity, Uint8 resistance);

/**
 * Applique l'effet de feu sur la surface donnée, dans les limites de
 * rect.  Attention: la surface doit être verrouillée!
 */
void fire(SDL_Surface * surface, SDL_Rect * rect);


#endif
