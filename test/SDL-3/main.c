#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "SDL.h"

#include "animation.h"
#include "time.h"

char letsexit = 0;

/* Nombre d'explosions simultan�es et valeur 
   par d�faut */
#define DEFAULT_EXPLO 10
static int nb_explo;

/* L'animation et les tableaux contenant les
   animators ainsi que leurs positions */
static animation anim;
static animator * player = NULL;
static SDL_Rect * pos = NULL;

SDL_Surface * screen;

/* R�alloue la taille des tableaux pour
   n explosions */
void allocate_explosions(int n) {
  nb_explo = n;
  player = (animator *) realloc(player, sizeof(animator) * nb_explo);
  pos = (SDL_Rect *) realloc(pos, sizeof(SDL_Rect) * nb_explo);
}

/* Initialise une animation nouvellement allou�e */
void init_explosion(int i) {
  /* Position al�atoire sur l'�cran */
  pos[i].x = rand() % (screen->w - player[i].anim->frames[0].image->w);
  pos[i].y = rand() % (screen->h - player[i].anim->frames[0].image->h);
  /* Position al�atoire dans l'animation */
  player[i].current_frame = rand() % player[i].anim->nbr_of_frames;
  player[i].counter = rand() % player[i].anim->frames[player[i].current_frame].delay;
}

/* Gestion des entr�es clavier */
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
	/* Plus d'explosions */
      case SDLK_KP_PLUS:
	allocate_explosions(nb_explo + 1);
	animator_init(&player[nb_explo - 1], &anim);
	animator_play(&player[nb_explo - 1]);
	init_explosion(nb_explo - 1);
	printf("Nombre d'explosions: %d\n", nb_explo);
	break;
	/* Moins d'explosions */
      case SDLK_KP_MINUS:
	if (nb_explo == 0) break;
	allocate_explosions(nb_explo - 1);
	printf("Nombre d'explosions: %d\n", nb_explo);
	break;
	/* Plus rapide */
      case SDLK_PAGEUP:
	time_set_game_speed(game_speed + 5);
	printf("Vitesse de jeu: %d cycles/seconde\n", game_speed);
	break;
	/* Moins rapide */
      case SDLK_PAGEDOWN:
	if (game_speed < 5) time_set_game_speed(1);
	else time_set_game_speed(game_speed - 5);
	printf("Vitesse de jeu: %d cycles/seconde\n", game_speed);
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
  SDL_Surface * img;
  int i;
  
  if (SDL_Init(SDL_INIT_VIDEO) == -1) {
    printf("Erreur lors de l'initialisation de SDL!\n");
    return 1;
  }
  
  screen = SDL_SetVideoMode(640, 480, 24, 
			    SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_ANYFORMAT);

  /* Cr�ation de l'animation */
  animation_init(&anim, 3);
  /* Frame 0, d�lai 10 cycles */
  img = SDL_LoadBMP("explo1.bmp");
  SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 0xff, 0x00, 0xff));
  animation_setframe(&anim, 0, img, 10);
  /* Frame 1, d�lai 15 cycles */
  img = SDL_LoadBMP("explo2.bmp");
  SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 0xff, 0x00, 0xff));
  animation_setframe(&anim, 1, img, 15);
  /* Frame 2, d�lai 30 cycles */
  img = SDL_LoadBMP("explo3.bmp");
  SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 0xff, 0x00, 0xff));
  animation_setframe(&anim, 2, img, 30);
  
  /* Allocation de initialisation des explosions et de leur position */
  allocate_explosions(DEFAULT_EXPLO);
  for (i = 0; i < nb_explo; i++) {
    animator_init(&player[i], &anim);
    animator_play(&player[i]);
    init_explosion(i);
  }
  /* Initialisation du temps avant la boucle principale */
  time_init();
  /* Ces variables nous permettront de calculer les FPS
     (frames per second, images par seconde) */
  Uint32 timer1 = SDL_GetTicks(), timer2;
  int frames_per_second = 0;
  /* Boucle de jeu */
  while (!letsexit) {
    int k;
    /* Mise � jour des entr�es et du temps */
    input_update();
    time_update();
    /* Remplissage de l'�cran en bleu */
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0x00, 0x00, 0xff));
    
    /* Mise � jour de l'�tat interne du jeu. cycles_to_calculate nous indique 
       de combien de cycles avancer pour garder une vitesse coh�rente */
    for (k = 0; k < cycles_to_calculate; k++) {
      /* Mise � jour des explosions */
      for (i = 0; i < nb_explo; i++) {
	animator_update(&player[i]);
	
	/* Si l'animation vient de boucler... */
	if (player[i].current_frame == 0 && player[i].counter == 0) {
	  /* ... on lui change sa position al�atoirement */
	  pos[i].x = rand() % (screen->w - img->w);
	  pos[i].y = rand() % (screen->h - img->h);
	}
      }
    }
    
    /* Dessiner les explosions sur l'�cran */
    for (i = 0; i < nb_explo; i++)
      animator_draw(&player[i], screen, &pos[i]);
    
    /* Afficher l'�cran que l'on vient de dessiner */
    SDL_Flip(screen);
    
    /* Calculer les fps */
    frames_per_second++;
    timer2 = SDL_GetTicks();
    /* Une seconde s'est �coul�e? Afficher le nombre d'�crans 
       dessin�s et r�initialiser */
    if (timer2 - timer1 > 1000) {
      printf("FPS: %d\n", frames_per_second);
      timer1 = timer2;
      frames_per_second = 0;
    }
  }
  
  /* Lib�ration des ressources allou�es */
  free(player);
  free(pos);
  animation_cleanup(&anim);
  
  SDL_Quit();
  return 0;
}
