#include <SDL/SDL.h>
#include "SDL_LoadPNG.h"

static int current = -1;
static SDL_Surface *background = NULL;
static char *img_bg[] = {
	"img/background_01.png",
	"img/background_02.png",
	"img/background_03.png",
	"img/background_04.png",
	"img/background_05.png",
	"img/background_06.png",
	"img/background_07.png",
	"img/background_08.png",
	"img/background_09.png",
	"img/background_10.png",
	"img/background_11.png",
	"img/background_12.png",
	"img/background_13.png"
};

SDL_Surface *get_background(level) {
	level--;
	if(level >= 12) level = 12;
	if(level != current) {
		if(background != NULL)
			SDL_FreeSurface(background);
		current = level;
		background = SDL_LoadPNG(img_bg[current]);
	}
	return background;
}
