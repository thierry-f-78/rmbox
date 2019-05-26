/*
 * Copyright 2011-2019 Thierry FOURNIER
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version
 * 2 of the License.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"

struct pixel_img_buf {
	int b;
	int g;
	int r;
	int a;
};

void flou(struct vimg * in, struct vimg *out, int flou){
	int i, j, seuil, x, y, stop;
	int tmp_r, tmp_g, tmp_b, tmp_a;
	int flou_2;
	struct pixel_img_buf * buf;

	// calcule la division
	flou_2 = ( flou + flou + 1 ) * ( flou + flou + 1 );

	// allocation de la memoire necessaire au traitement
	buf = calloc(sizeof(struct pixel_img_buf), in->width * in->height);

	// application du flou
	// premier passage sur la matrice: on fait la moyenne de toutes les lignes horizontales
	seuil = in->width;
	i = 0;
	x = 0;
	// calcul de la moyenne de 5 pixels horizontaux
	while(i < in->width * in->height){
		// calcul du pixel de depart de la moyenne
		// si on est proche de de limite de debut de ligne de moins de flou pixel, on met le debut de la ligne
		if(x < flou){
			// position de debut de ligne
			j = i - x;
		} else {
			// position du premier pixel dans le calcul de la moyenne
			j = i - flou;
		}
		// calcul de la borne de fin
		if(x < in->width - flou){
			// position du dernier pixel dans le calcul de moyenne
			stop = i + flou + 1;
		} else {
			// position de fin de ligne
			stop = i + in->width - x;
		}
		// on parcours les pixel choisis
		while(j < stop){
			buf[i].r += in->pixel_data[j].r;
			buf[i].g += in->pixel_data[j].g;
			buf[i].b += in->pixel_data[j].b;
			buf[i].a += in->pixel_data[j].a;
			j++;
		}

		// incremente le compteur de ligne
		x++;

		// incremente le compteur de la matrice
		i++;

		// detection du dernier pixel de la ligne
		if(i == seuil){
			// on fixe le prochain seuil
			seuil = i + in->width;
			// on remet le compteur de ligne a 0
			x = 0;
		}
	}

	// calcul de la moyenne de 5 pixels verticaux
	seuil = in->width;
	i = 0;
	y = 0;
	while(i < in->width * in->height){
		// calcul du pixel de depart de la moyenne
		// si on est proche de de limite de debut de ligne de moins de flou pixel, on met le debut de la ligne
		if(y < flou){
			// position de debut de ligne
			j = i - ( y * in->width );
		} else {
			// position du premier pixel dans le calcul de la moyenne
			j = i - ( flou * in->width );
		}
		// calcul de la borne de fin
		if(y < in->height - flou){
			// position du dernier pixel dans le calcul de moyenne
			stop = i + ( flou * in->width ) + 1;
		} else {
			// position de fin de ligne
			stop = i + ( in->height - y ) * in->width;
		}
		// on parcours les pixel choisis
		tmp_r = 0;
		tmp_g = 0;
		tmp_b = 0;
		tmp_a = 0;
		while(j < stop){
			tmp_r += buf[j].r;
			tmp_g += buf[j].g;
			tmp_b += buf[j].b;
			tmp_a += buf[j].a;
			j += in->width;
		}

		// on calcule la moyenne
		out->pixel_data[i].r = tmp_r / flou_2;
		out->pixel_data[i].g = tmp_g / flou_2;
		out->pixel_data[i].b = tmp_b / flou_2;
		out->pixel_data[i].a = tmp_a / flou_2;

		// incremente le compteur de la matrice
		i++;

		// detection du dernier pixel de la ligne
		if(i == seuil){
			// on fixe le prochain seuil
			seuil = i + in->width;
			// on remet le compteur de ligne a 0
			y++;
		}
	}

	free(buf);
}

