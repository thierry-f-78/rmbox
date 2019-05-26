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
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

#include <time.h>
#include <sys/time.h>

#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>

#include <SDL/SDL.h>

#include "images.h"
#include "structs.h"
#include "forms.h"
#include "rmbox.h"
#include "flou.h"
#include "collision.h"

#include "check_level.h"
#include "background.h"
#include "collision.h"
#include "SDL_LoadPNG.h"

/*
struct area {
	int x1;
	int y1;
	int x2;
	int y2;
};
*/

// time
struct timeval current_time = {0, 0};
struct timeval last_valid_time;
struct timeval real_time;

SDL_Surface *background;
SDL_Surface *screen;
SDL_Surface *chif[11];
SDL_Surface *tile_bomb_b[5];
SDL_Surface *tile_bomb_l[5];
SDL_Surface *tile_del[5];
SDL_Surface *tile_delload[5];
SDL_Surface *tile_color_b[5];
SDL_Surface *tile_color_l[5];
SDL_Surface *smiley;
SDL_Surface *img_pause;
//const struct area pad = {247, 15, 624, 392};

void x_draw_bg(void) {
	int i, j, cx, cy, bx;
	int x, y;
	int len, pad, flou_pos;
	int tmp, aff;
	SDL_Surface *tile_color;
	SDL_Surface *tile_bomb;
	SDL_Surface *pad_bg;
	/*
	struct pixel_img data_del_tile[TILE_SZ * TILE_SZ];
	struct vimg del_tile = {
		.height = TILE_SZ,
		.width = TILE_SZ,
		.pixel_data = data_del_tile
	};
	*/
	// sert a calculer le channel alpha a appliquer pour les ombres
	static struct pixel_img data_shd[((4*TILE_SZ)+20)][((4*TILE_SZ)+20)];
	static struct vimg shd = {
		.height = (4*TILE_SZ)+20,
		.width = (4*TILE_SZ)+20,
		.pixel_data = (struct pixel_img *)data_shd
	};
	SDL_Rect blitrect = {0, 0, 0, 0};
	SDL_Rect blitsrc  = {0, 0, 0, 0};

	// affiche le fond
	SDL_BlitSurface(background, NULL, screen, NULL);

	// affiche le score
	cx = pos_score.x1;
	cy = pos_score.y1;
	len = 1;
	if(aff_points < points) aff_points++;
	tmp = aff_points;
	j = 1;
	i = 100000000;
	while(i > 0){
		if(j == 0 || i <= tmp){
			len = 0;
			aff = tmp / i;
			tmp -= aff * i;
			blitrect.x = cx;
			blitrect.y = cy;
			SDL_BlitSurface(chif[aff], NULL, screen, &blitrect);
			cx += CHIF_LEN;
			j = 0;
		}
		i /= 10;
	}
	if(len == 1){
		blitrect.x = cx;
		blitrect.y = cy;
		SDL_BlitSurface(chif[0], NULL, screen, &blitrect);
	}

	// affiche le level
	cx = pos_level.x1;
	cy = pos_level.y1;
	tmp = level;
	j = 1;
	i = 100;
	while(i > 0){
		if(j == 0 || i <= tmp){
			aff = tmp / i;
			tmp -= aff * i;
			blitrect.x = cx;
			blitrect.y = cy;
			SDL_BlitSurface(chif[aff], NULL, screen, &blitrect);
			cx += CHIF_LEN;
			j = 0;
		}
		i /= 10;
	}
	
	// affiche le temps
	cx = pos_time.x1;
	cy = pos_time.y1;
	tmp = start_time / 60;
	j = 1;
	i = 10000;
	len = 1;
	while(i > 0){
		if(j == 0 || i <= tmp){
			len = 0;
			aff = tmp / i;
			tmp -= aff * i;
			blitrect.x = cx;
			blitrect.y = cy;
			SDL_BlitSurface(chif[aff], NULL, screen, &blitrect);
			cx += CHIF_LEN;
			j = 0;
		}
		i /= 10;
	}
	if(len == 1){
		blitrect.x = cx;
		blitrect.y = cy;
		SDL_BlitSurface(chif[0], NULL, screen, &blitrect);
		cx += CHIF_LEN;
	}
	blitrect.x = cx;
	blitrect.y = cy;
	SDL_BlitSurface(chif[10], NULL, screen, &blitrect);

	cx += CHIF_LEN;
	tmp = start_time % 60;
	j = 1;
	i = 10;
	while(i > 0){
		if(j == 0 || i <= tmp){
			aff = tmp / i;
			tmp -= aff * i;
			blitrect.x = cx;
			blitrect.y = cy;
			SDL_BlitSurface(chif[aff], NULL, screen, &blitrect);
			cx += CHIF_LEN;
			j = 0;
		} else {
			blitrect.x = cx;
			blitrect.y = cy;
			SDL_BlitSurface(chif[0], NULL, screen, &blitrect);
			cx += CHIF_LEN;
		}
		i /= 10;
	}

	// genere la grille
	blitrect.x = 247;
	blitrect.y = 15;
	pad_bg = get_background(level);
	SDL_BlitSurface(pad_bg, NULL, screen, &blitrect);

	// pause
	// si, l'on n'est pas en pause
	if(st_pause == 0){

		i = 0;
		while(i < 9 * 9){
			switch(grid_pos[i].type){
				case G_EMPTY:
					if(grid_pos[i].tmout > 0){

						if(grid_pos[i].tmout <= TAFFD && 
						   grid_pos[i].tmout >= TAFFD-ONIMG){
							tile_color = tile_del[0];
							tmp = 255;
						} else
						if(grid_pos[i].tmout <= TAFFD-ONIMG-1 &&
						   grid_pos[i].tmout >= TAFFD-(ONIMG*2)){
							tile_color = tile_del[1];
							tmp = 204;
						} else
						if(grid_pos[i].tmout <= TAFFD-(ONIMG*2)-1 &&
						   grid_pos[i].tmout >= TAFFD-(ONIMG*3)){
							tile_color = tile_del[2];
							tmp = 153;
						} else
						if(grid_pos[i].tmout <= TAFFD-(ONIMG*3)-1 &&
						   grid_pos[i].tmout >= TAFFD-(ONIMG*4)){
							tile_color = tile_del[3];
							tmp = 102;
						} else
						if(grid_pos[i].tmout <= TAFFD-(ONIMG*4)-1 &&
						   grid_pos[i].tmout >= TAFFD-(ONIMG*5)){
							tile_color = tile_del[4];
							tmp = 51;
						} else {
							goto passe_delete;
						}

						// afiche le tile
						/*
						blitrect.x = grid_pos[i].x;
						blitrect.y = grid_pos[i].y;
						SDL_BlitSurface(del_tile, NULL, screen, &blitrect);
						*/
						// affiche l'animation
						blitrect.x = grid_pos[i].x;
						blitrect.y = grid_pos[i].y;
						SDL_BlitSurface(tile_color, NULL, screen, &blitrect);

						passe_delete: ;
						// affiche le score e le faisant
						// disparaitre progressivement
/*
						set_alpha(tile_points[grid_pos[i].points], &del_tile,
						          255 * grid_pos[i].tmout / TAFFD );
						put_image_alpha(&affx, &del_tile, 
						                grid_pos[i].x, grid_pos[i].y,
						                0, 0,
						                del_tile.width,
						                del_tile.height);
*/							
					}
					break;
	
				case 2:
					blitrect.x = grid_pos[i].x;
					blitrect.y = grid_pos[i].y;
					SDL_BlitSurface(tile_unbreak, NULL, screen, &blitrect);
					break;
	
				case G_BOMB:
					// select tile
					blitrect.x = grid_pos[i].x;
					blitrect.y = grid_pos[i].y;
					SDL_BlitSurface(tile_bomb_b[cur_us/200000], NULL, screen, &blitrect);
					break;

				case G_BLOCK:
					// select tile
					blitrect.x = grid_pos[i].x;
					blitrect.y = grid_pos[i].y;
					SDL_BlitSurface(tile_color_b[grid_pos[i].color], NULL, screen, &blitrect);
					break;
			}
			i++;
		}
	
		// dessine le contenu du BAC
		j = 0;
		while(j < 5){
			if(bac_sort[j]->actif == 0){
				j++;
				continue;
			}
	
			// select tile
			tile_color = tile_color_l[bac_sort[j]->color];
	
			// repere le carré utile et centre celui ci
			// recherche la position x
			x = 0;
			while(x < 4){
				if(bac_sort[j]->desc[x +  0] >= 1 || 
				   bac_sort[j]->desc[x +  4] >= 1 || 
				   bac_sort[j]->desc[x +  8] >= 1 || 
				   bac_sort[j]->desc[x + 12] >= 1){
					break;
				}
				x++;
			}
			// recherche la position y
			y = 0;
			while(y < 4){
				if(bac_sort[j]->desc[(y * 4) +  0] >= 1 ||
				   bac_sort[j]->desc[(y * 4) +  1] >= 1 ||
				   bac_sort[j]->desc[(y * 4) +  2] >= 1 ||
				   bac_sort[j]->desc[(y * 4) +  3] >= 1){
					break;
				}
				y++;
			}
			// recherche la position x
			cx = 3;
			while(cx >= 0){
				if(bac_sort[j]->desc[cx +  0] >= 1 || 
				   bac_sort[j]->desc[cx +  4] >= 1 || 
				   bac_sort[j]->desc[cx +  8] >= 1 || 
				   bac_sort[j]->desc[cx + 12] >= 1){
					break;
				}
				cx--;
			}
			// recherche la position y
			cy = 3;
			while(y >= 0){
				if(bac_sort[j]->desc[(cy * 4) +  0] >= 1 ||
				   bac_sort[j]->desc[(cy * 4) +  1] >= 1 ||
				   bac_sort[j]->desc[(cy * 4) +  2] >= 1 ||
				   bac_sort[j]->desc[(cy * 4) +  3] >= 1){
					break;
				}
				cy--;
			}
			cx = (cx - x + 1) * TILE_SZ_L;
			cy = (cy - y + 1) * TILE_SZ_L;
			x *= TILE_SZ_L;
			y *= TILE_SZ_L;
	
			// calcul du centrage
			cx = bac_pos[j].x1 + (4*TILE_SZ_L/2) - (cx/2) - x;
			cy = bac_pos[j].y1 + (4*TILE_SZ_L/2) - (cy/2) - y;
			bx = cx;
			i = 0;
			while(i < 4 * 4){
			
				if(bac_sort[j]->desc[i] == 1){
					blitrect.x = cx;
					blitrect.y = cy;
					SDL_BlitSurface(tile_color, NULL, screen, &blitrect);
				} else
				if(bac_sort[j]->desc[i] == 2){
					blitrect.x = cx;
					blitrect.y = cy;
					SDL_BlitSurface(tile_bomb_l[cur_us/200000], NULL, screen, &blitrect);
				}
				if(i % 4 == 3){
					cx = bx;
					cy += TILE_SZ_L;
				} else {
					cx += TILE_SZ_L;
				}
				i++;
			}
			j++;
		}
	}

	// dessine en pause
	else {
		// contenu du bac
		j = 0;
		while(j < 5){
			blitrect.x = bac_pos[j].x1;
			blitrect.y = bac_pos[j].y1;
			SDL_BlitSurface(smiley, NULL, screen, &blitrect);
			j++;
		}

		// pad de jeu
		i = 0;
		while(i < 9 * 9){
			if(pause_pos[i].tmout > 0){
				tile_color = NULL;
				if(pause_pos[i].tmout <= TAFFD && 
				   pause_pos[i].tmout >= TAFFD-ONIMG){
					tile_color = tile_del[0];
				} else
				if(pause_pos[i].tmout <= TAFFD-ONIMG-1 &&
				   pause_pos[i].tmout >= TAFFD-(ONIMG*2)){
					tile_color = tile_del[1];
				} else
				if(pause_pos[i].tmout <= TAFFD-(ONIMG*2)-1 &&
				   pause_pos[i].tmout >= TAFFD-(ONIMG*3)){
					tile_color = tile_del[2];
				} else
				if(pause_pos[i].tmout <= TAFFD-(ONIMG*3)-1 &&
				   pause_pos[i].tmout >= TAFFD-(ONIMG*4)){
					tile_color = tile_del[3];
				} else
				if(pause_pos[i].tmout <= TAFFD-(ONIMG*4)-1 &&
				   pause_pos[i].tmout >= TAFFD-(ONIMG*5)){
					tile_color = tile_del[4];
				}
				if(tile_color != NULL){
					blitrect.x = pause_pos[i].x;
					blitrect.y = pause_pos[i].y;
					SDL_BlitSurface(tile_color, NULL, screen, &blitrect);
				}
			}
			i++;
		}

		// pause explication
		blitrect.x = pos_pause.x1;
		blitrect.y = pos_pause.y1;
		SDL_BlitSurface(img_pause, NULL, screen, &blitrect);
	}
	
	// dessine le timer
	// calcul du % a afficher
	blitsrc.w = ( timer_pos.x2 - timer_pos.x1 ) * c_timer / WAIT_TIME;
	blitsrc.h = 26;
	blitrect.x = timer_pos.x1;
	blitrect.y = timer_pos.y1;
	SDL_BlitSurface(timer, &blitsrc, screen, &blitrect);

	if(st_pause == 0){

		// dessine le curseur
		if(cur_form->actif != 0){
			if(cur_x >= docking.x1 && cur_x <= docking.x2 &&
			   cur_y >= docking.y1 && cur_y <= docking.y2 ){
				tile_color = tile_color_l[cur_form->color];
				tile_bomb = tile_bomb_l[cur_us/200000];
				pad = TILE_SZ_L;
				flou_pos = 5;
			} else {
				tile_color = tile_color_b[cur_form->color];
				tile_bomb = tile_bomb_b[cur_us/200000];
				pad = TILE_SZ;
				flou_pos = 10;
			}
			i = shd.width;
			shd.width = ( pad * 4 ) + 20;
			shd.height = ( pad * 4 ) + 20;
			if(i != shd.width)cur_change = 1;
/*
			// ombre
			// si il y a eu chagement (rotation redimensionnement)
			// on recalcule l'ombre
			if(cur_change == 1){	
				cur_change = 0;	
			
				// on prepare le calque entierement transparent (et noir)
				memset(shd.pixel_data, 0x00,
				       4 * shd.width * shd.height * sizeof(char));
			
				// calcule la longueur d'un saut
				len = shd.width - pad + 1;
	
				// pointe sur le premier carre a farcir
				j = ( shd.width * flou_pos ) + flou_pos;
	
				// copie les carres
				i = 0;
			 	while(i < 4 * 4){
					if(cur_form->desc[i] == 1){
						tmp = j;
						x = 0;
						y = 0;
						while(x < pad * pad){
							shd.pixel_data[tmp].r = 0x10;
							shd.pixel_data[tmp].g = 0x10;
							shd.pixel_data[tmp].b = 0x10;
							shd.pixel_data[tmp].a = 0xff;
							if(x % pad == pad - 1){				
								tmp += len;
							} else {
								tmp++;
							}
							x++;
						}
					}
					if(i % 4 == 3){
						j -= 3 * pad;
						j += pad * shd.width;
					} else {
						j += pad;
					}
					i++;
				}

				// application du flou
				flou(&shd, &shd, FLOU);
			}
	
			// dessin de l'ombre
			cx = cur_x - (cur_form->mouse_x * pad) - (pad / 2);
			cy = cur_y - (cur_form->mouse_y * pad) - (pad / 2);
			put_image_alpha(&affx, &shd, cx, cy, 0, 0, shd.width, shd.height);
*/	
			// forme elle meme
			cx = cur_x - (cur_form->mouse_x * pad) - (pad / 2);
			cy = cur_y - (cur_form->mouse_y * pad) - (pad / 2);
			bx = cx;
			i = 0;
			while(i < 4 * 4){	
				if(cur_form->desc[i] == 1){
					blitrect.x = cx;
					blitrect.y = cy;
					SDL_BlitSurface(tile_color, NULL, screen, &blitrect);
				} else
				if(cur_form->desc[i] == 2){
					blitrect.x = cx;
					blitrect.y = cy;
					SDL_BlitSurface(tile_bomb, NULL, screen, &blitrect);
				}
				if(i % 4 == 3){
					cx = bx;
					cy += pad;
				} else {
					cx += pad;
				}
				i++;
			}
		}
	}

	// display datas
	SDL_Flip(screen);
}

// echange le contenu actif de la souris avec celui du bac
void swap_bac(int bac){
	struct tile_desc * tmp;

	tmp = cur_form;
	cur_form = bac_sort[bac];
	bac_sort[bac] = tmp;
}

// genere une nouvelle piece
void x_new_bac(int nbac){
	int bac, i, tmp;

	// si aucun bac precisé (5) on cherche le 1er vide
	if(nbac == 5){
		bac = 0;
		while(bac<5){
			if(bac_sort[bac]->actif==0){
				break;
			}
			bac++;
		}
	} else {
		bac = nbac;
	}
	if(bac == 5){
		// les bac sont pleins
		// on voit si c'est game over
		if(is_any_placable(bac_sort[0], grid_pos) == 1 ||
		   is_any_placable(bac_sort[1], grid_pos) == 1 ||
		   is_any_placable(bac_sort[2], grid_pos) == 1 ||
		   is_any_placable(bac_sort[3], grid_pos) == 1 ||
		   is_any_placable(bac_sort[4], grid_pos) == 1 ||
			(cur_form->actif==1 && is_any_placable(cur_form, grid_pos) == 1) ){
			// sinon on genere un empechement au hasard
			do {
				i = rand()%(9 * 9);
			} while(grid_pos[i].type != G_EMPTY);
			grid_pos[i].type = G_UNBREAK;
		} else {
			SDL_Quit();
			exit(0);
		}
		return;
	}
	
	// choix d'une piece en fonction du level:
	do {
		tmp = rand() % NB_TILES;
	} while(forms[tmp].level > level);

	memcpy(bac_sort[bac]->desc, forms[tmp].desc, 4 * 4);
	bac_sort[bac]->color = (rand()%5);
	bac_sort[bac]->actif = 1;
	i=0;
	while(i < 4 * 4){
		if(bac_sort[bac]->desc[i] == 1){	
			bac_sort[bac]->mouse_x = i % 4;
			bac_sort[bac]->mouse_y = i / 4;
			break;
		}
		i++;
	}

	// si on a depassé le level 5, on peut trouver une bombe
	if(level >= BOMB_LEVEL && rand() % BOMB_PROB == 0){
		do {
			i = rand() % ( 4 * 4 );
		} while(bac_sort[bac]->desc[i] != 1);
		bac_sort[bac]->desc[i] = 2;
	}
}

void x_time(int signum){
	int i;

	if(st_pause == 0){
		// timer
		c_timer += TIMER_IT;
		if(c_timer >= WAIT_TIME){
			c_timer = 0;
			x_new_bac(5);
		}

		// temps de la partie
		cur_us += TIMER_IT;
		if(cur_us >= 1000000){
			start_time++;
			cur_us -= 1000000;
		}

		// gere les effets de disparition de points
		i = 0;
		while(i < 9 * 9){
			grid_pos[i].tmout -= TIMER_IT;
			if(grid_pos[i].tmout<0) grid_pos[i].tmout = 0;
			i++;
		}
	} else {
		// affiche deux disparition au pif
		do {
			i = rand() % ( 9 * 9 );
		} while(pause_pos[i].tmout != 0);
		pause_pos[i].tmout = TAFFD;
		do {
			i = rand() % ( 9 * 9 );
		} while(pause_pos[i].tmout != 0);
		pause_pos[i].tmout = TAFFD;

		// gere les effets de disparition de points
		i = 0;
		while(i < 9 * 9){
			pause_pos[i].tmout -= TIMER_IT;
			if(pause_pos[i].tmout < 0) pause_pos[i].tmout = 0;
			i++;
		}
	}

	// changement de level
	level = check_level(points);
}

int main(void){
	SDL_Event event;
	int i, j;
	int cur, tmp, col;
	int nblines, nbcol;

	// initialise l'ecran
	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		fprintf(stderr, "Erreur lors de l'initialisation de SDL: %s\n", SDL_GetError());
		return 1;
	}	
	screen = SDL_SetVideoMode(640, 480, 24, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_ANYFORMAT);

	// init random
	srand(time(NULL));

	// init
	start_time = 0;
	aff_points = 0;
	level = 1;

	// get new bac
	x_new_bac(5);

	// load pictures
	background      = SDL_LoadPNG("img/background.png");
	chif[0]         = SDL_LoadPNG("img/c_0.png");
	chif[1]         = SDL_LoadPNG("img/c_1.png");
	chif[2]         = SDL_LoadPNG("img/c_2.png");
	chif[3]         = SDL_LoadPNG("img/c_3.png");
	chif[4]         = SDL_LoadPNG("img/c_4.png");
	chif[5]         = SDL_LoadPNG("img/c_5.png");
	chif[6]         = SDL_LoadPNG("img/c_6.png");
	chif[7]         = SDL_LoadPNG("img/c_7.png");
	chif[8]         = SDL_LoadPNG("img/c_8.png");
	chif[9]         = SDL_LoadPNG("img/c_9.png");
	chif[10]        = SDL_LoadPNG("img/c_10.png");
	tile_unbreak    = SDL_LoadPNG("img/tile_unbreak.png");
	tile_bomb_b[0]  = SDL_LoadPNG("img/tile_bomb_0.png");
	tile_bomb_b[1]  = SDL_LoadPNG("img/tile_bomb_1.png");
	tile_bomb_b[2]  = SDL_LoadPNG("img/tile_bomb_2.png");
	tile_bomb_b[3]  = SDL_LoadPNG("img/tile_bomb_3.png");
	tile_bomb_b[4]  = SDL_LoadPNG("img/tile_bomb_4.png");
	tile_bomb_l[0]  = SDL_LoadPNG("img/ll_tile_bomb_0.png");
	tile_bomb_l[1]  = SDL_LoadPNG("img/ll_tile_bomb_1.png");
	tile_bomb_l[2]  = SDL_LoadPNG("img/ll_tile_bomb_2.png");
	tile_bomb_l[3]  = SDL_LoadPNG("img/ll_tile_bomb_3.png");
	tile_bomb_l[4]  = SDL_LoadPNG("img/ll_tile_bomb_4.png");
	timer           = SDL_LoadPNG("img/timer.png");
	tile_del[0]     = SDL_LoadPNG("img/tile_delete_01_03.png");
	tile_del[1]     = SDL_LoadPNG("img/tile_delete_04_06.png");
	tile_del[2]     = SDL_LoadPNG("img/tile_delete_07_09.png");
	tile_del[3]     = SDL_LoadPNG("img/tile_delete_10_12.png");
	tile_del[4]     = SDL_LoadPNG("img/tile_delete_13_15.png");
	smiley          = SDL_LoadPNG("img/smiley.png");
	img_pause       = SDL_LoadPNG("img/pause.png");
	tile_color_l[0] = SDL_LoadPNG("img/ll_tile_color_green.png");
	tile_color_l[1] = SDL_LoadPNG("img/ll_tile_color_red.png");
	tile_color_l[2] = SDL_LoadPNG("img/ll_tile_color_pink.png");
	tile_color_l[3] = SDL_LoadPNG("img/ll_tile_color_yellow.png");
	tile_color_l[4] = SDL_LoadPNG("img/ll_tile_color_blue.png");
	tile_color_b[0] = SDL_LoadPNG("img/tile_color_green.png");
	tile_color_b[1] = SDL_LoadPNG("img/tile_color_red.png");
	tile_color_b[2] = SDL_LoadPNG("img/tile_color_pink.png");
	tile_color_b[3] = SDL_LoadPNG("img/tile_color_yellow.png");
	tile_color_b[4] = SDL_LoadPNG("img/tile_color_blue.png");

	// init timer
	gettimeofday(&last_valid_time, NULL);

	// main program
	while(1) {

		// wait a little bit
		usleep(10000);

		// check time
		gettimeofday(&real_time, NULL);
		current_time.tv_sec += real_time.tv_sec - last_valid_time.tv_sec;
		current_time.tv_usec += real_time.tv_usec - last_valid_time.tv_usec;
		if(current_time.tv_usec > 1000000){
			current_time.tv_usec-=1000000;
			current_time.tv_sec++;
		}
		last_valid_time.tv_sec = real_time.tv_sec;
		last_valid_time.tv_usec = real_time.tv_usec;

		while(SDL_PollEvent(&event)){
			switch (event.type) {

				// ----------------------------------------
				//  La souris a bouge
				// ----------------------------------------
				case SDL_MOUSEMOTION:
					cur_x += event.motion.xrel;
					cur_y += event.motion.yrel;
					break;

				// ----------------------------------------
				//  Appuie d'un bouton de souris
				// ----------------------------------------
				case SDL_MOUSEBUTTONDOWN: 

					switch(event.button.button) {
						case SDL_BUTTON_LEFT:

							// verifie si l'on est dans un bac
							i = 0;
							while(i < 5){
								if(cur_x >= bac_pos[i].x1 && cur_x <= bac_pos[i].x2 &&
								   cur_y >= bac_pos[i].y1 && cur_y <= bac_pos[i].y2 ){
									// si le bac et la souris sont vides
									// on rempli le bac
									if(bac_sort[i]->actif == 0 && cur_form->actif == 0){
										c_timer = 0;
										x_new_bac(i);

									// sinon on echange le bac avec la souris
									} else {
										swap_bac(i);
										cur_change = 1;
									}
								}
								i ++;
							}
				
							// verifie si l'on est sur le terrain de jeu
							if(cur_x >= pad.x1 && cur_x <= pad.x2 &&
							   cur_y >= pad.y1 && cur_y <= pad.y2 ){
								// depose des carrés
					
								// si pas de carre on passe
								if(cur_form->actif == 0) break;
					
								// on recherche la position du care pointé
								i=0;
								while(i < 9 * 9){
									if(cur_x >= grid_pos[i].x &&
									   cur_x <= grid_pos[i].x + TILE_SZ &&
									   cur_y >= grid_pos[i].y &&
									   cur_y <= grid_pos[i].y + TILE_SZ){
											break;
										}
									i++;
								}
					
								// on verifie que tous les carres entrent
								// if(is_placable(i, cur_form, &grid_pos) == 0){
								if(is_placable(i, cur_form, grid_pos) == 0){
									goto end_posable;
								}

								// on pose
								// pointeur sur le premier carré
								cur = i - cur_form->mouse_x - ( cur_form->mouse_y * 9);
								j = 0;
								while(j < 4*4){
									if(cur_form->desc[j] == 1){
										grid_pos[cur].type = G_BLOCK;
										grid_pos[cur].color = cur_form->color;

										// on ajoute des points
										points++;
									} 
									else if(cur_form->desc[j] == 2){
										grid_pos[cur].type = G_BOMB;
									}
									// carre suivant
									if(j % 4 == 3){
										cur += ( 9 - 4 + 1 );
									} else {
										cur ++;
									}
									j ++;
								}

								// on efface le total des points
								bzero(grid_del, 9 * 9 * sizeof(int));
								bzero(grid_col, 9 * 9 * sizeof(int));
								bzero(grid_car, 9 * 9 * sizeof(int));
								nbcol = 0;
								nblines = 0;
					
								// on verifie les lignes a eclater
								// horizontal:
								i = 0;
								while(i < 9 * 9){
									j = i;
									tmp = 1;
									col = 1;
									cur = grid_pos[j].color;
									while(j < i + 9){
										if(grid_pos[j].color != cur) col = 0;
										if(grid_pos[j].type != G_BLOCK &&
										   grid_pos[j].type != G_BOMB){
											tmp = 0;
											break;
										}
										j++;
									}
									if(tmp == 1){
										nblines++;
										if(col == 1) nbcol++;
										j = i;
										while(j < i + 9){
											grid_del[j] = 1;
											if(col == 1) grid_col[j] = 1;
											j++;
										}
									}
									i += 9;
								}
					
								// vertical
								i = 0;
								while(i < 9){
									j = i;
									tmp = 1;
									col = 1;
									cur = grid_pos[j].color;
									while(j < i + ( 8 * 9 ) + 1){
										if(grid_pos[j].color != cur) col = 0;
										if(grid_pos[j].type != G_BLOCK &&
			                        grid_pos[j].type != G_BOMB){
											tmp = 0;
											break;
										}
										j += 9;
									}
									if(tmp == 1){
										nblines++;
										if(col == 1) nbcol++;
										j = i;
										while(j < i + ( 8 * 9 ) + 1){
											grid_del[j] = 1;
											if(col == 1) grid_col[j] = 1;
											j += 9;
										}
									}
									i ++;
								}
	
								// si on a des lignes detruites, on additionne
								// les points
								if(nblines > 0){
									// on multiplie la matrice de lignes
									// par le nombre de lignes detruites
									j = 0;
									while(j < 9 * 9){
										// on totalise les points
										grid_del[j] = (grid_del[j] * nblines) + 
										              (grid_col[j] * nbcol) +
													     grid_car[j];
										points += grid_del[j];

										// on efface et on mets a jour
										if(grid_del[j] > 0){
											grid_pos[j].type = G_EMPTY;
											grid_pos[j].points = grid_del[j];
											grid_pos[j].tmout = TAFFD;
										}
										j++;
									}
								}
					
								// carre de 4 de la meme couleur

								// on vide la souris
								cur_form->actif = 0;
								
								// si aucun dock plein, on le remplit,
								// et on remet le timer a 0
								i = 0;
								while(i < 5){
									if(bac_sort[i]->actif == 1) break;
									i++;
								}
								if(i == 5){
									c_timer = 0;
									x_new_bac(5);
								}
					
								end_posable: ;
							}
							break;

						case SDL_BUTTON_RIGHT:
							// si une piece n'est pas sous la souris
							// on quite
							if(cur_form->actif == 0) break;

							// fait tourner la piece
							rotate(cur_form);

							// informe du changement pour recalculer l'ombre
							cur_change = 1;
							break;
					}
					break;

				/* traitement des évènements de type KeyPress */
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym) {
						case SDLK_p:
							if(st_pause == 1){
								st_pause = 0;
							} else {
								st_pause = 1;
							}
							break;

						case SDLK_ESCAPE:
						case SDLK_q:
							SDL_Quit();
							return 0;
							break;

						default:
							break;
					}
			}
		}
		x_time(0);
		x_draw_bg();
	}
	exit(0);
}

