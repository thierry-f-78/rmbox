#ifndef __FLOU_H__
#define __FLOU_H__

/**
 * l'image de sortie peut etre la meme que celle d'entree
 *
 * @param in: image a flouer
 * @param out: image de sortie (doit etre convenablement allouée)
 * @param flou: niveau de flou:
 *        1: 3x3
 *        2: 5x5
 *        3: 7x7
 *        4: 9x9
 *        ...
 */
void flou(struct vimg * in, struct vimg *out, int flou);

#endif
