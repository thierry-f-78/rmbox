#include "animation.h"
#include <stdlib.h>

void animation_frame_init(animation_frame * frame, SDL_Surface * image, Uint16 delay) {
  frame->image = image;
  frame->delay = delay;
}

void animation_frame_cleanup(animation_frame * frame) {
  if (frame->image) SDL_FreeSurface(frame->image);
}

void animation_frame_draw(animation_frame * frame, SDL_Surface * dest, SDL_Rect * pos) {
  SDL_BlitSurface(frame->image, (SDL_Rect *)NULL, dest, pos);
}

void animation_init(animation * anim, Uint16 nbr_of_frames) {
  anim->frames = (animation_frame *) calloc(nbr_of_frames, sizeof(animation_frame));
  anim->nbr_of_frames = nbr_of_frames;
}

void animation_setframe(animation * anim, Uint16 pos, SDL_Surface * surface, Uint16 delay) {
  animation_frame_cleanup(&anim->frames[pos]);
  animation_frame_init(&anim->frames[pos], surface, delay);
}

void animation_cleanup(animation * anim) {
  int i;
  for (i = 0; i < anim->nbr_of_frames; i++)
    animation_frame_cleanup(&anim->frames[i]);

  free(anim->frames);
}

void animator_init(animator * ator, animation * anim) {
  ator->anim = anim;
  animator_rewind(ator);
}

void animator_play(animator * ator) {
  ator->status = PLAY;
}

void animator_stop(animator * ator) {
  ator->status = STOP;
}

void animator_rewind(animator * ator) {
  ator->current_frame = 0;
  ator->counter = 0;
  animator_stop(ator);
}

void animator_nextframe(animator * ator) {
  /* Retour à la frame 0 si nous sommes à la dernière */
  if (++ator->current_frame == ator->anim->nbr_of_frames) ator->current_frame = 0;
  ator->counter = 0;
}

void animator_update(animator * ator) {
  const animation_frame * frame;

  /* Ne mettre à jour l'animation que si elle est jouée */
  if (ator->status != PLAY) return;

  frame = &ator->anim->frames[ator->current_frame];
  if (frame->delay == 0) return;

  /* Passage à la frame suivante? */
  if (++ator->counter == frame->delay) animator_nextframe(ator);
}

void animator_draw(animator * ator, SDL_Surface * dest, SDL_Rect * pos) {
  animation_frame_draw(&ator->anim->frames[ator->current_frame], dest, pos);
}
