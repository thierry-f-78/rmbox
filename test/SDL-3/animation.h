#ifndef ANIMATION_H__
#define ANIMATION_H__

#include "SDL.h"

typedef struct
{
  SDL_Surface * image;
  Uint16 delay;
} animation_frame;

void animation_frame_init(animation_frame * frame, SDL_Surface * image, Uint16 delay);
void animation_frame_cleanup(animation_frame * frame);
void animation_frame_draw(animation_frame * frame, SDL_Surface * dst, SDL_Rect * pos);

typedef struct
{
  Uint16 nbr_of_frames;
  animation_frame * frames;
}animation;

void animation_init(animation * anim, Uint16 nbr_of_frames);
void animation_setframe(animation * anim, Uint16 pos, SDL_Surface * surface,
			Uint16 delay);
void animation_cleanup(animation * anim);

typedef struct
{
  const animation * anim;
  enum { STOP, PLAY } status;
  Uint16 current_frame;
  Uint16 counter;
}animator;

void animator_init(animator * ator, animation * anim);
void animator_play(animator * ator);
void animator_stop(animator * ator);
void animator_rewind(animator * ator);
void animator_nextframe(animator * ator);
void animator_update(animator * ator);
void animator_draw(animator * ator, SDL_Surface * dest, SDL_Rect * pos);

#endif
