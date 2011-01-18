// variables en vrac pour l'affichage X11
Display *dpy;
int screen; 
Window root;
Visual *visual;
int depth;
int fg, bg; 
GC gc;
Window win;
XImage * xbuf;
XMotionEvent * e;

// nombre de points
int points;

// nombre de points a afficher
// sert pour l'effetd e compteur
int aff_points;

// position courante du pointeur de souris
int cur_x = 0;
int cur_y = 0;

// lock sur les fonctions de dessins
int drawing = 0;

// level en cours
int level = 1;

// compte les microsencondes avant 
// la generation d'une nouvelle piece
int c_timer = 0;

// donne les microsecondes en cours
// sert a incrementer les secondes
// du chonometrage de la partie
int cur_us = 0;
// compteur des secondes
int start_time;

// indique l'etat courant de la pause
int pause = 0;

// indique si la forme de la piece deplacée
// a changée de maniere a reclaculer le flou
int cur_change = 0;

// init tiles
struct vimg * tile_color_b[] = {
	&tile_color_red,
	&tile_color_green,
	&tile_color_yellow,
	&tile_color_pink,
	&tile_color_blue
};
struct vimg * tile_color_l[] = {
	&tile_color_red_l,
	&tile_color_green_l,
	&tile_color_yellow_l,
	&tile_color_pink_l,
	&tile_color_blue_l
};
	
// init points tiles
struct vimg * tile_points[] = {
	[ 1] = &tile_bg_1p,
	[ 2] = &tile_bg_2p,
	[ 3] = &tile_bg_3p,
	[ 4] = &tile_bg_4p,
	[ 5] = &tile_bg_5p,
	[ 6] = &tile_bg_6p,
	[ 7] = &tile_bg_7p,
	[ 8] = &tile_bg_8p,
	[20] = &tile_bg_20p,
	[21] = &tile_bg_21p,
	[22] = &tile_bg_22p,
	[23] = &tile_bg_23p,
	[24] = &tile_bg_24p,
	[25] = &tile_bg_25p,
	[26] = &tile_bg_26p,
	[27] = &tile_bg_27p,
	[28] = &tile_bg_28p
};

// anim d'effacement
struct vimg * tile_del[] = {
	&tile_delete_01_03,
	&tile_delete_04_06,
	&tile_delete_07_09,
	&tile_delete_10_12,
	&tile_delete_13_15
};

// anim bombe
struct vimg * tile_bomb_l[] = {
	&tile_bomb_0_l,
	&tile_bomb_1_l,
	&tile_bomb_2_l,
	&tile_bomb_3_l,
	&tile_bomb_4_l
};
struct vimg * tile_bomb_b[] = {
	&tile_bomb_0_b,
	&tile_bomb_1_b,
	&tile_bomb_2_b,
	&tile_bomb_3_b,
	&tile_bomb_4_b
};
	
// init background
struct vimg * pad_bg[] = {
	[ 1] = &pad_bg_01,
	[ 2] = &pad_bg_02,
	[ 3] = &pad_bg_03,
	[ 4] = &pad_bg_04,
	[ 5] = &pad_bg_05,
	[ 6] = &pad_bg_06,
	[ 7] = &pad_bg_07,
	[ 8] = &pad_bg_08,
	[ 9] = &pad_bg_09,
	[10] = &pad_bg_10,
	[11] = &pad_bg_11,
	[12] = &pad_bg_12,
	[13] = &pad_bg_13
};
	
// init chiffres
struct vimg * tile_bg[7];
struct vimg * chif[] = {
	&c_0,
	&c_1,
	&c_2,
	&c_3,
	&c_4,
	&c_5,
	&c_6,
	&c_7,
	&c_8,
	&c_9,
	&c__
};
	
// init bac
struct tile_desc a[6] = {
	[0] = {
		.actif = 0
	},
	[1] = {
		.actif = 0
	},
	[2] = {
		.actif = 0
	},
	[3] = {
		.actif = 0
	},
	[4] = {
		.actif = 0
	},
	[5] = {
		.actif = 0
	}
};
struct tile_desc * bac_sort[5] = {
	&a[0],
	&a[1],
	&a[2],
	&a[3],
	&a[4]
};
struct tile_desc * cur_form = &a[5];

// sert de buffer d'affichage
struct pixel_img affx_buf[WIDTH * HEIGHT];
struct vimg affx = {
	.width = WIDTH,
	.height = HEIGHT,
	.pixel_data = affx_buf
};

struct area {
	int x1;
	int y1;
	int x2;
	int y2;
};

const struct area docking = {247, 393, 624, 479};
const struct area pad = {247, 15, 624, 392};
const struct area timer_pos = {41, 424, 199, 449};
const struct area pos_score = {48, 208, 0, 0};
const struct area pos_level = {48, 354, 0, 0};
const struct area pos_time  = {48, 280, 0, 0};
const struct area pos_pause  = {170, 165, 0, 0};

const struct area bac_pos[5] = {
	{262, 405, 321, 464},
	{334, 405, 393, 464},
	{406, 405, 465, 464},
	{478, 405, 537, 464},
	{550, 405, 609, 464}
};

int grid_del[9 * 9];
int grid_col[9 * 9];
int grid_car[9 * 9];

struct coord grid_pos[9 * 9] = {
	{247, 15, 1, 0, 0, 0},
	{289, 15, 1, 0, 0, 0},
	{331, 15, 1, 0, 0, 0},
	{373, 15, 1, 0, 0, 0},
	{415, 15, 1, 0, 0, 0},
	{457, 15, 1, 0, 0, 0},
	{499, 15, 1, 0, 0, 0},
	{541, 15, 1, 0, 0, 0},
	{583, 15, 1, 0, 0, 0},
	
	{247, 57, 1, 0, 0, 0},
	{289, 57, 1, 0, 0, 0},
	{331, 57, 1, 0, 0, 0},
	{373, 57, 1, 0, 0, 0},
	{415, 57, 1, 0, 0, 0},
	{457, 57, 1, 0, 0, 0},
	{499, 57, 1, 0, 0, 0},
	{541, 57, 1, 0, 0, 0},
	{583, 57, 1, 0, 0, 0},
	
	{247, 99, 1, 0, 0, 0},
	{289, 99, 1, 0, 0, 0},
	{331, 99, 1, 0, 0, 0},
	{373, 99, 1, 0, 0, 0},
	{415, 99, 1, 0, 0, 0},
	{457, 99, 1, 0, 0, 0},
	{499, 99, 1, 0, 0, 0},
	{541, 99, 1, 0, 0, 0},
	{583, 99, 1, 0, 0, 0},
	
	{247, 141, 1, 0, 0, 0},
	{289, 141, 1, 0, 0, 0},
	{331, 141, 1, 0, 0, 0},
	{373, 141, 1, 0, 0, 0},
	{415, 141, 1, 0, 0, 0},
	{457, 141, 1, 0, 0, 0},
	{499, 141, 1, 0, 0, 0},
	{541, 141, 1, 0, 0, 0},
	{583, 141, 1, 0, 0, 0},
	
	{247, 183, 1, 0, 0, 0},
	{289, 183, 1, 0, 0, 0},
	{331, 183, 1, 0, 0, 0},
	{373, 183, 1, 0, 0, 0},
	{415, 183, 1, 0, 0, 0},
	{457, 183, 1, 0, 0, 0},
	{499, 183, 1, 0, 0, 0},
	{541, 183, 1, 0, 0, 0},
	{583, 183, 1, 0, 0, 0},
	
	{247, 225, 1, 0, 0, 0},
	{289, 225, 1, 0, 0, 0},
	{331, 225, 1, 0, 0, 0},
	{373, 225, 1, 0, 0, 0},
	{415, 225, 1, 0, 0, 0},
	{457, 225, 1, 0, 0, 0},
	{499, 225, 1, 0, 0, 0},
	{541, 225, 1, 0, 0, 0},
	{583, 225, 1, 0, 0, 0},
	
	{247, 267, 1, 0, 0, 0},
	{289, 267, 1, 0, 0, 0},
	{331, 267, 1, 0, 0, 0},
	{373, 267, 1, 0, 0, 0},
	{415, 267, 1, 0, 0, 0},
	{457, 267, 1, 0, 0, 0},
	{499, 267, 1, 0, 0, 0},
	{541, 267, 1, 0, 0, 0},
	{583, 267, 1, 0, 0, 0},
	
	{247, 309, 1, 0, 0, 0},
	{289, 309, 1, 0, 0, 0},
	{331, 309, 1, 0, 0, 0},
	{373, 309, 1, 0, 0, 0},
	{415, 309, 1, 0, 0, 0},
	{457, 309, 1, 0, 0, 0},
	{499, 309, 1, 0, 0, 0},
	{541, 309, 1, 0, 0, 0},
	{583, 309, 1, 0, 0, 0},
	
	{247, 351, 1, 0, 0, 0},
	{289, 351, 1, 0, 0, 0},
	{331, 351, 1, 0, 0, 0},
	{373, 351, 1, 0, 0, 0},
	{415, 351, 1, 0, 0, 0},
	{457, 351, 1, 0, 0, 0},
	{499, 351, 1, 0, 0, 0},
	{541, 351, 1, 0, 0, 0},
	{583, 351, 1, 0, 0, 0}
};

struct coord pause_pos[9 * 9] = {
	{247, 15, 1, 0, 0, 0},
	{289, 15, 1, 0, 0, 0},
	{331, 15, 1, 0, 0, 0},
	{373, 15, 1, 0, 0, 0},
	{415, 15, 1, 0, 0, 0},
	{457, 15, 1, 0, 0, 0},
	{499, 15, 1, 0, 0, 0},
	{541, 15, 1, 0, 0, 0},
	{583, 15, 1, 0, 0, 0},
	
	{247, 57, 1, 0, 0, 0},
	{289, 57, 1, 0, 0, 0},
	{331, 57, 1, 0, 0, 0},
	{373, 57, 1, 0, 0, 0},
	{415, 57, 1, 0, 0, 0},
	{457, 57, 1, 0, 0, 0},
	{499, 57, 1, 0, 0, 0},
	{541, 57, 1, 0, 0, 0},
	{583, 57, 1, 0, 0, 0},
	
	{247, 99, 1, 0, 0, 0},
	{289, 99, 1, 0, 0, 0},
	{331, 99, 1, 0, 0, 0},
	{373, 99, 1, 0, 0, 0},
	{415, 99, 1, 0, 0, 0},
	{457, 99, 1, 0, 0, 0},
	{499, 99, 1, 0, 0, 0},
	{541, 99, 1, 0, 0, 0},
	{583, 99, 1, 0, 0, 0},
	
	{247, 141, 1, 0, 0, 0},
	{289, 141, 1, 0, 0, 0},
	{331, 141, 1, 0, 0, 0},
	{373, 141, 1, 0, 0, 0},
	{415, 141, 1, 0, 0, 0},
	{457, 141, 1, 0, 0, 0},
	{499, 141, 1, 0, 0, 0},
	{541, 141, 1, 0, 0, 0},
	{583, 141, 1, 0, 0, 0},
	
	{247, 183, 1, 0, 0, 0},
	{289, 183, 1, 0, 0, 0},
	{331, 183, 1, 0, 0, 0},
	{373, 183, 1, 0, 0, 0},
	{415, 183, 1, 0, 0, 0},
	{457, 183, 1, 0, 0, 0},
	{499, 183, 1, 0, 0, 0},
	{541, 183, 1, 0, 0, 0},
	{583, 183, 1, 0, 0, 0},
	
	{247, 225, 1, 0, 0, 0},
	{289, 225, 1, 0, 0, 0},
	{331, 225, 1, 0, 0, 0},
	{373, 225, 1, 0, 0, 0},
	{415, 225, 1, 0, 0, 0},
	{457, 225, 1, 0, 0, 0},
	{499, 225, 1, 0, 0, 0},
	{541, 225, 1, 0, 0, 0},
	{583, 225, 1, 0, 0, 0},
	
	{247, 267, 1, 0, 0, 0},
	{289, 267, 1, 0, 0, 0},
	{331, 267, 1, 0, 0, 0},
	{373, 267, 1, 0, 0, 0},
	{415, 267, 1, 0, 0, 0},
	{457, 267, 1, 0, 0, 0},
	{499, 267, 1, 0, 0, 0},
	{541, 267, 1, 0, 0, 0},
	{583, 267, 1, 0, 0, 0},
	
	{247, 309, 1, 0, 0, 0},
	{289, 309, 1, 0, 0, 0},
	{331, 309, 1, 0, 0, 0},
	{373, 309, 1, 0, 0, 0},
	{415, 309, 1, 0, 0, 0},
	{457, 309, 1, 0, 0, 0},
	{499, 309, 1, 0, 0, 0},
	{541, 309, 1, 0, 0, 0},
	{583, 309, 1, 0, 0, 0},
	
	{247, 351, 1, 0, 0, 0},
	{289, 351, 1, 0, 0, 0},
	{331, 351, 1, 0, 0, 0},
	{373, 351, 1, 0, 0, 0},
	{415, 351, 1, 0, 0, 0},
	{457, 351, 1, 0, 0, 0},
	{499, 351, 1, 0, 0, 0},
	{541, 351, 1, 0, 0, 0},
	{583, 351, 1, 0, 0, 0}
};
