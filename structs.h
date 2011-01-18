#ifndef __IMG_H__
#define __IMG_H__

// taille de l'aire de jeu
#define PAD_SIZE 9

// taille d'un groupe de bloc placable
#define BLOCK_SIZE 4

// nom du soft a afficher
#define TITLE "rmbox"

// taille de la fenetre
#define WIDTH 640
#define HEIGHT 480

// largeur d'un gros tile
#define TILE_SZ 42

// largeur d'un petit tile
#define TILE_SZ_L 15

// largeur d'un chiffre
#define CHIF_LEN 14

// probabilité d'apparition d'une bombe:
// % = 100 / BOMB_PROB
#define BOMB_PROB 10

// niveau a partir duquel les bombes arrivent
#define BOMB_LEVEL 1

// nombre de pixel a rendre flou sous l'ombre des pieces
#define FLOU 2

// temps entre deux images lors d'une animation (µs)
#define ONIMG 80000

// temps d'affichage des point lors de la destruction d'une ligne (µs)
#define TAFFD 1500000

// delai en microsenceondes entre deux rafraichissements de l'ecran
// 40000: 25 img / s
// 30000 =  img / s (bien)
// 20000: 50 img / s
// 8000 = 125 img / s
#define TIMER_IT 40000

// temps pour poser une piece (µs)
//#define WAIT_TIME 13000000
#define WAIT_TIME 10000000

// couleurs
#define C_RED 0
#define C_GREEN 1
#define C_YELLOW 2
#define C_PINK 3
#define C_BLUE 4

// types de blocks
#define G_EMPTY 1
#define G_UNBREAK 2
#define G_BLOCK 3
#define G_BOMB 4

// structure pour les images:
struct pixel_img {
	unsigned char b; 
	unsigned char g; 
	unsigned char r; 
	unsigned char a; 
};
struct vimg {
	unsigned int width;  
	unsigned int height; 
	struct pixel_img * pixel_data;
};
struct tile_desc {
	int color;
	int actif;
	int mouse_x;
	int mouse_y;
	char desc[4*4];
};
// repere de la grille:
struct coord {
int x;
int y;
	/* type:
	 * 1: empty
	 * 2: unbreakable
	 * 3	: block
	 * 4: bomb
	 */
	int type;
	/* color:
	 * 0: red
	 * 1: green
	 * 2: yellow
	 * 3: pink
	 * 4: blue
	 */
	int color;
	// pour la suppression de cases
	int points;
	int tmout;
	// pour l'explosion
};

#endif

