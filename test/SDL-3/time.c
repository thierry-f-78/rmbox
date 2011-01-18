#include "time.h"

static Uint32 timer1, timer2;

/* Nombre maximum de cycles � passer - au del�, le jeu
   sera ralenti */
#define MAX_SKIPPED_FRAMES 20
/* Variable globale indiquand le nombre de cycles � 
   calculer avant d'afficher une image */
Uint16 cycles_to_calculate = 0;

/* Vitesse par d�faut du jeu, en cycles par seconde */
#define DEFAULT_GAME_SPEED 70
/* Vitesse courante du jeu */
Uint16 game_speed;
/* Dur�e d'un cycle en millisecondes */
Uint16 cycle_length;

/* Initialise le syst�me temporel */
void time_init() {
  time_set_game_speed(DEFAULT_GAME_SPEED);
}

/* Affecte la vitesse du jeu, en cycles par seconde */
void time_set_game_speed(Uint16 speed) {
  if (speed == 0) speed = 1;
  game_speed = speed;
  cycle_length = 1000 / game_speed;
  timer1 = SDL_GetTicks();
}

/* Mise � jour du temps et des variables associ�es */
void time_update() {
  /* S'assurer que l'on ne va pas trop vite... */
  while (1) {
    timer2 = SDL_GetTicks() - timer1;
    
    if (timer2 >= cycle_length) break;
    else SDL_Delay(3);
  }
  
  /* Mise � jour de l'�tat des timers et des variables
     globales - timer1 va contenir le "surplus" de 
     timer2 par rapport au temps que l'on aurait exactement
     d� passer, cycles_to_calculate le nombre de cycles �
     faire jouer avant d'afficher une nouvelle image */
  timer1 = SDL_GetTicks() - (timer2 % cycle_length);
  cycles_to_calculate = timer2 / cycle_length;
  /* V�rifier la limite des cycles � sauter */
  if (cycles_to_calculate > MAX_SKIPPED_FRAMES) cycles_to_calculate = MAX_SKIPPED_FRAMES;
}
