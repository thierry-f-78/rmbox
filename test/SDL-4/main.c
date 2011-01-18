#include <stdio.h>
#include <stdlib.h>
#include "SDL.h"

#include "fire.h"

/* Variables d'intensités, de vivacité et de résistance */
#define DEFAULT_INTENSITY 150
#define DEFAULT_VIVACITY 128
#define DEFAULT_RESISTANCE 75

static Uint8 intensity = DEFAULT_INTENSITY;
static Uint8 vivacity = DEFAULT_VIVACITY;
static Uint8 resistance = DEFAULT_RESISTANCE;

static Sint8 intensity_delta = 0;
static Sint8 vivacity_delta = 0;
static Sint8 resistance_delta = 0;

/* Mise à 1 s'il faut quitter */
Uint8 letsexit = 0;

SDL_Surface * screen, * image;

/* Gestion des entrées clavier */
void input_update() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_KEYDOWN:
      switch (event.key.keysym.sym) {
	/* Quitter */
      case SDLK_ESCAPE:
	letsexit = 1;
	break;
	/* Enflammement du logo SDL - il suffit de le dessiner
	 et de laisser l'effet de feu faire le reste */
      case SDLK_RETURN:
	{
	  SDL_Rect blitRect = { 0, 0, 0, 0 };
	  blitRect.x = (rand() % (screen->w - image->w));
	  blitRect.y = (rand() % (screen->h - image->h));

	  SDL_BlitSurface(image, NULL, screen, &blitRect);
	  break;
	}
	/* Augmenter intensité */
      case SDLK_UP:
	intensity_delta = 1;
	break;
	/* Diminuer intensité */
      case SDLK_DOWN:
	intensity_delta = -1;
	break;
	/* Augmenter résistance */
      case SDLK_RIGHT:
	resistance_delta = 1;
	break;
	/* Diminuer résistance */
      case SDLK_LEFT:
	resistance_delta = -1;
	break;
	/* Augmenter vivacité */
      case SDLK_PAGEUP:
	vivacity_delta = 1;
	break;
	/* Diminuer vivacité */
      case SDLK_PAGEDOWN:
	vivacity_delta = -1;
	break;
      default:
	break;
      }
      break;
      /* Remise à zéro du delta des variables de paramètre du foyer si
       une touche leur correspondant est relâchée */
    case SDL_KEYUP:
      switch (event.key.keysym.sym) {
      case SDLK_UP:
      case SDLK_DOWN:
	intensity_delta = 0;
	break;
      case SDLK_RIGHT:
      case SDLK_LEFT:
	resistance_delta = 0;
	break;
      case SDLK_PAGEUP:
      case SDLK_PAGEDOWN:
	vivacity_delta = 0;
	break;
      default:
	break;
      }
      break;
    default:
      break;
    }
  }
}

int main(int argc, char * argv[]) {
  /* Rectangles dans lesquels vont s'appliquer le foyer et l'effet de
     feu */
  SDL_Rect rootRect, fireRect;
  /* Surface temporaire pour charger l'image */
  SDL_Surface * tmp;

  if (SDL_Init(SDL_INIT_VIDEO) == -1) {
    printf("Erreur lors de l'initialisation de SDL!\n");
    return 1;
  }
  
  screen = SDL_SetVideoMode(320, 240, 24, 
			    SDL_SWSURFACE);

  /* Le foyer est appliqué aux deux dernières lignes */
  rootRect.x = 0;
  rootRect.y = screen->h - 2;
  rootRect.w = screen->w;
  rootRect.h = 2;

  /* L'effet de feu s'applique sur tout l'écran, à l'exception
     des deux dernières */
  fireRect.x = 0;
  fireRect.y = 0;
  fireRect.w = screen->w;
  fireRect.h = screen->h - 2;

  /* Création de l'image du logo SDL */
  tmp = SDL_LoadBMP("image.bmp");
  image = SDL_DisplayFormat(tmp);
  SDL_FreeSurface(tmp);
  SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, 0xff, 0x00, 0xff));

  /* Boucle principale */
  while (!letsexit) {
    /* Mise à jour des entrées */
    input_update();

    /* Mise à jour des paramètre du foyer */
    if ((intensity + intensity_delta) < 0) intensity = 0;
    else if ((intensity + intensity_delta) > 255) intensity = 255;
    else intensity += intensity_delta;
    if (intensity_delta != 0) printf("Intensité: %d\n", intensity);

    if ((vivacity + vivacity_delta) < 0) vivacity = 0;
    else if ((vivacity + vivacity_delta) > 255) vivacity = 255;
    else vivacity += vivacity_delta;
    if (vivacity_delta != 0) printf("Vivacité: %d\n", vivacity);

    if ((resistance + resistance_delta) < 0) resistance = 0;
    else if ((resistance + resistance_delta) > 255) resistance = 255;
    else resistance += resistance_delta;
    if (resistance_delta != 0) printf("Résistance: %d\n", resistance);

    /* Ne pas oublier de verrouiller la surface que l'on va directement
       modifier! */
    SDL_LockSurface(screen);
    fireRoot(screen, &rootRect, intensity, vivacity, resistance);
    fire(screen, &fireRect);
    SDL_UnlockSurface(screen);
        
    /* Mise à jour de l'écran */
    SDL_Flip(screen);    
  }
  
  SDL_Quit();
  return 0;
}
