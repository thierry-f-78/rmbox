#ifndef TIME_H__
#define TIME_H__

#include "SDL.h"

extern Uint16 cycles_to_calculate;
extern Uint16 game_speed;
extern Uint16 cycle_length;

void time_init();
void time_set_game_speed(Uint16 speed);
void time_update();

#endif
