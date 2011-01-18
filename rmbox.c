#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <sys/time.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>

#include "images.h"
#include "structs.h"
#include "forms.h"
#include "rmbox.h"
#include "flou.h"
#include "sprites.h"
#include "collision.h"

extern int errno;

void x_draw_bg(void) {
	int i, j, cx, cy, bx;
	int x, y;
	int len, pad, flou_pos;
	unsigned int pixel;
	int tmp, aff;
	int cpx, cpy, cpwidth, cpheight;
	struct vimg * tile_color;
	struct vimg * tile_bomb;
	struct vimg * shadow;
	struct pixel_img data_del_tile[TILE_SZ * TILE_SZ];
	struct vimg del_tile = {
		.height = TILE_SZ,
		.width = TILE_SZ,
		.pixel_data = data_del_tile
	};
	// sert a calculer le channel alpha a appliquer pour les ombres
	static struct pixel_img data_shd[((4*TILE_SZ)+20)][((4*TILE_SZ)+20)];
	static struct vimg shd = {
		.height = (4*TILE_SZ)+20,
		.width = (4*TILE_SZ)+20,
		.pixel_data = (struct pixel_img *)data_shd
	};

	// lock
	if(drawing == 1){
		return;
	}
	drawing=1;

	// affiche le fond
	put_image(&affx, &background, 0, 0, 0, 0,
	          background.width, background.height);

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
			put_image(&affx, chif[aff], cx, cy, 0, 0,
			          chif[aff]->width, chif[aff]->height);
			cx += CHIF_LEN;
			j = 0;
		}
		i /= 10;
	}
	if(len == 1){
		put_image(&affx, chif[0], cx, cy, 0, 0,
		          chif[0]->width, chif[0]->height);
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
			put_image(&affx, chif[aff], cx, cy, 0, 0,
			          chif[aff]->width, chif[aff]->height);
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
			put_image(&affx, chif[aff], cx, cy, 0, 0,
			          chif[aff]->width, chif[aff]->height);
			cx += CHIF_LEN;
			j = 0;
		}
		i /= 10;
	}
	if(len == 1){
		put_image(&affx, chif[0], cx, cy, 0, 0,
		          chif[0]->width, chif[0]->height);
		cx += CHIF_LEN;
	}
	put_image(&affx, chif[10], cx, cy, 0, 0,
	          chif[10]->width, chif[10]->height);
	cx += CHIF_LEN;
	tmp = start_time % 60;
	j = 1;
	i = 10;
	while(i > 0){
		if(j == 0 || i <= tmp){
			aff = tmp / i;
			tmp -= aff * i;
			put_image(&affx, chif[aff], cx, cy, 0, 0,
			          chif[aff]->width, chif[aff]->height);
			cx += CHIF_LEN;
			j = 0;
		} else {
			put_image(&affx, chif[0], cx, cy, 0, 0,
			          chif[0]->width, chif[0]->height);
			cx += CHIF_LEN;
		}
		i /= 10;
	}
	
	// genere la grille
	put_image(&affx, pad_bg[level],
	          247, 15,
	          0, 0,
	          pad_bg[level]->width, pad_bg[level]->height);
	// pause
	// si, l'on n'est pas en pause
	if(pause == 0){

		i = 0;
		while(i < 9 * 9){
			switch(grid_pos[i].type){
				case G_EMPTY:
					if(grid_pos[i].tmout > 0){

						if(grid_pos[i].tmout <= TAFFD && 
						   grid_pos[i].tmout >= TAFFD-ONIMG){
							tile_color = tile_del[4];
							tmp = 255;
						} else
						if(grid_pos[i].tmout <= TAFFD-ONIMG-1 &&
						   grid_pos[i].tmout >= TAFFD-(ONIMG*2)){
							tile_color = tile_del[3];
							tmp = 204;
						} else
						if(grid_pos[i].tmout <= TAFFD-(ONIMG*2)-1 &&
						   grid_pos[i].tmout >= TAFFD-(ONIMG*3)){
							tile_color = tile_del[2];
							tmp = 153;
						} else
						if(grid_pos[i].tmout <= TAFFD-(ONIMG*3)-1 &&
						   grid_pos[i].tmout >= TAFFD-(ONIMG*4)){
							tile_color = tile_del[1];
							tmp = 102;
						} else
						if(grid_pos[i].tmout <= TAFFD-(ONIMG*4)-1 &&
						   grid_pos[i].tmout >= TAFFD-(ONIMG*5)){
							tile_color = tile_del[0];
							tmp = 51;
						} else {
							goto passe_delete;
						}
	
						// rend le tile transparent
						set_alpha(tile_color_b[grid_pos[i].color],
						          &del_tile, (unsigned char)tmp);
	
						// afiche le tile
						put_image_alpha(&affx, &del_tile,
						                grid_pos[i].x, grid_pos[i].y,
						                0, 0,
					 	                del_tile.width,
						                del_tile.height);
	
						// affiche l'animation
						put_image_alpha(&affx, tile_color, 
						                grid_pos[i].x, grid_pos[i].y,
						                0, 0,
						                tile_color->width,
						                tile_color->height);
				
						passe_delete:
						// affiche le score e le faisant
						// disparaitre progressivement
						set_alpha(tile_points[grid_pos[i].points], &del_tile,
						          255 * grid_pos[i].tmout / TAFFD );
						put_image_alpha(&affx, &del_tile, 
						                grid_pos[i].x, grid_pos[i].y,
						                0, 0,
						                del_tile.width,
						                del_tile.height);
					}
					break;
	
				case 2:
					put_image(&affx, &tile_unbreak,
					          grid_pos[i].x, grid_pos[i].y,
					          0, 0,
				 	          tile_unbreak.width, tile_unbreak.height);
					break;
	
				case G_BOMB:
					// select tile
					put_image(&affx, tile_bomb_b[cur_us/200000],
					          grid_pos[i].x, grid_pos[i].y,
					          0, 0,
				 	          tile_bomb_b[cur_us/200000]->width,
					          tile_bomb_b[cur_us/200000]->height);
					break;

				case G_BLOCK:
					// select tile
					put_image(&affx, tile_color_b[grid_pos[i].color],
					          grid_pos[i].x, grid_pos[i].y,
					          0, 0,
				 	          tile_color_b[grid_pos[i].color]->width,
					          tile_color_b[grid_pos[i].color]->height);
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
					put_image(&affx, tile_color, cx, cy, 0, 0,
					          tile_color->width, tile_color->height);
				} else
				if(bac_sort[j]->desc[i] == 2){
					put_image(&affx, tile_bomb_l[cur_us/200000], cx, cy, 0, 0,
					          tile_bomb_l[cur_us/200000]->width,
					          tile_bomb_l[cur_us/200000]->height);
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

	// dessine en pause
	} else {
		// contenu du bac
		j = 0;
		while(j < 5){
			put_image_alpha(&affx, &smiley,
			                bac_pos[j].x1, bac_pos[j].y1,
			                0, 0,
			                smiley.width, smiley.height);
			j++;
		}

		// pad de jeu
		i = 0;
		while(i < 9 * 9){
			if(pause_pos[i].tmout > 0){
				tile_color = NULL;
				if(pause_pos[i].tmout <= TAFFD && 
				   pause_pos[i].tmout >= TAFFD-ONIMG){
					tile_color = tile_del[4];
				} else
				if(pause_pos[i].tmout <= TAFFD-ONIMG-1 &&
				   pause_pos[i].tmout >= TAFFD-(ONIMG*2)){
					tile_color = tile_del[3];
				} else
				if(pause_pos[i].tmout <= TAFFD-(ONIMG*2)-1 &&
				   pause_pos[i].tmout >= TAFFD-(ONIMG*3)){
					tile_color = tile_del[2];
				} else
				if(pause_pos[i].tmout <= TAFFD-(ONIMG*3)-1 &&
				   pause_pos[i].tmout >= TAFFD-(ONIMG*4)){
					tile_color = tile_del[1];
				} else
				if(pause_pos[i].tmout <= TAFFD-(ONIMG*4)-1 &&
				   pause_pos[i].tmout >= TAFFD-(ONIMG*5)){
					tile_color = tile_del[0];
				}
				if(tile_color != NULL){
					put_image_alpha(&affx, tile_color, 
					                pause_pos[i].x, pause_pos[i].y,
					                0, 0,
					                tile_color->width,
					                tile_color->height);
				}
			}
			i++;
		}

		// pause explication
		put_image_alpha(&affx, &img_pause,
		                pos_pause.x1, pos_pause.y1,
		                0, 0,
		                img_pause.width, img_pause.height);
	}
	
	// dessine le timer
	// calcul du % a afficher
	len = ( timer_pos.x2 - timer_pos.x1 ) * c_timer / WAIT_TIME;

	// affichage du remplissage
	put_image(&affx, &timer, timer_pos.x1, timer_pos.y1, 0, 0,
	          len, timer.height);

	if(pause == 0 ){
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
	
			// forme elle meme
			cx = cur_x - (cur_form->mouse_x * pad) - (pad / 2);
			cy = cur_y - (cur_form->mouse_y * pad) - (pad / 2);
			bx = cx;
			i = 0;
			while(i < 4 * 4){	
				if(cur_form->desc[i] == 1){
					put_image(&affx, tile_color, cx, cy, 0, 0,
					          tile_color->width, tile_color->height);
				} else
				if(cur_form->desc[i] == 2){
					put_image(&affx, tile_bomb, cx, cy, 0, 0,
					          tile_bomb->width, tile_bomb->height);
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

	// affiche a l'ecran
	XPutImage(dpy, win, gc, xbuf, 0, 0, 0, 0,
	          xbuf->width, xbuf->height);
	XFlush(dpy);

	// unlock
	drawing = 0;
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
		if(is_any_placable(bac_sort[0], &grid_pos) == 1 ||
		   is_any_placable(bac_sort[1], &grid_pos) == 1 ||
		   is_any_placable(bac_sort[2], &grid_pos) == 1 ||
		   is_any_placable(bac_sort[3], &grid_pos) == 1 ||
		   is_any_placable(bac_sort[4], &grid_pos) == 1 ||
			(cur_form->actif==1 && is_any_placable(cur_form, &grid_pos) == 1) ){
			// sinon on genere un empechement au hasard
			do {
				i = rand()%(9 * 9);
			} while(grid_pos[i].type != G_EMPTY);
			grid_pos[i].type = G_UNBREAK;
		} else {
			XCloseDisplay(dpy);
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

	if(pause == 0){
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
	if(points >= 100 && points < 199){
		level = 2;
	} else
	if(points >= 200 && points < 299){
		level = 2;
	} else
	if(points >= 300 && points < 399){
		level = 3;
	} else
	if(points >= 400 && points < 499){
		level = 4;
	} else
	if(points >= 500 && points < 599){
		level = 5;
	} else
	if(points >= 600 && points < 699){
		level = 6;
	} else
	if(points >= 700 && points < 799){
		level = 7;
	} else
	if(points >= 800 && points < 899){
		level = 8;
	} else
	if(points >= 900 && points < 999){
		level = 9;
	} else
	if(points >= 1000 && points < 1099){
		level = 10;
	} else
	if(points >= 1100 && points < 1199){
		level = 11;
	} else
	if(points >= 1200 && points < 999999999){
		level = 12;
	}

	// redessine l'ecran
	x_draw_bg();
}

int main(void){
	XEvent report;
	char base[4*4];
	struct itimerval value;
	int i, j;
	int x, y;
	int tile_x, tile_y;
	int cur, tmp, col;
	int nblines, nbcol;
	char key;

	// initialise l'ecran
	XSetWindowAttributes xswa;
	XGCValues gcvalues;

	if((dpy=XOpenDisplay(NULL))==NULL) {
		fprintf(stderr, "x display: can not connect "
		"to server %s\n",XDisplayName(NULL));
		exit(1);
	}
	
	// Initialisation des variables standards
	screen = DefaultScreen(dpy);
	root = DefaultRootWindow(dpy);
	visual = DefaultVisual(dpy, screen);
	depth = DefaultDepth(dpy,screen);
	fg = BlackPixel(dpy, screen);
	bg = WhitePixel(dpy, screen);

	if(depth < 24){
		fprintf(stderr, "may be run in minimun depth 24, "
		"current depth=%d", depth); 
		exit(1);
	}
	
	gcvalues.foreground =  fg;
	gcvalues.background =  bg;

	gc =  XCreateGC(dpy, RootWindow(dpy, screen),
	               (GCForeground | GCBackground), &gcvalues);

	// attributs de la fenetre.
	// Le motif en fond
	xswa.background_pixel = bg;

	// Les événements
	xswa.event_mask = KeyPressMask | KeyReleaseMask |
	                  ButtonPressMask |	ButtonReleaseMask |
							PointerMotionMask | Button1MotionMask |
	                  Button2MotionMask | Button3MotionMask |
	                  Button4MotionMask | Button5MotionMask |
	                  ButtonMotionMask | ExposureMask |
	                  VisibilityChangeMask;

	// Couleur de la bordure et du background
	xswa.background_pixel = bg;
	xswa.border_pixel     = fg;
	win = XCreateWindow(dpy, root,
	                    100, 100, WIDTH, HEIGHT, 3,
	                    depth, InputOutput, visual,
	                    CWEventMask|CWBorderPixel|CWBackPixel,
	                    &xswa);

	// On lui donne un titre
	XChangeProperty(dpy, win, XA_WM_NAME, XA_STRING, 8,
	                PropModeReplace,
	                TITLE, sizeof(TITLE) - 1);
	                XMapWindow(dpy,win);

	// Creation de l'image buffer local
	xbuf = XCreateImage(dpy, visual, depth,
	       ZPixmap, 0,
	       (char *)&affx.pixel_data[0],
	       affx.width,
	       affx.height, 32, 0);
	if(xbuf == NULL){   
		fprintf(stderr, "Erreur XCreateImage: ${NAME}\n");
		exit(1);
	}

	// init random
	srand(time(NULL));

	// init
	start_time = 0;

	// get new bac
	x_new_bac(5);

	// init timer
	signal(SIGALRM, x_time);
	value.it_interval.tv_sec = 0;
	value.it_interval.tv_usec = TIMER_IT;
	value.it_value = value.it_interval;
	setitimer(ITIMER_REAL, &value, NULL);

	// main program
	while(1) {
		XNextEvent(dpy, &report);
		switch (report.type) {

			// Le programme doit rafraichir la fenetre
			case Expose:

			// La souris a bouge
			case MotionNotify:
			e = (XMotionEvent *) &report;
			cur_x = e->x;
			cur_y = e->y;
			break;

			case ButtonPress: 
			switch(report.xbutton.button) {
				case Button1: 
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
						} else
						if(cur_form->desc[j] == 2){
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

				case Button3:
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
			case KeyPress:
				XLookupString(&(report.xkey), &key, 1, NULL, NULL);

				// printf("%02x\n", key);

				switch(key){
					case 'p':
					case 'P':
						if(pause == 1){
							pause = 0;
						} else {
							pause = 1;
						}
						break;

					case 0x1b: // echap
					case 'q':
					case 'Q':
						XCloseDisplay(dpy);
						exit(0);
						break;
				}
				break;

			/* traitement des évènements de type ConfigureNotify */
			case ConfigureNotify:
				break;
		}
	}
	exit(0);
}

