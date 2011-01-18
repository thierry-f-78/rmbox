#include <string.h>

#include "structs.h"

/**
 * rotation: effectue une rotation de la piece
 */
void rotate(struct tile_desc *tile){
	unsigned char base[BLOCK_SIZE * BLOCK_SIZE];
	int i;

	memcpy(base, tile->desc, BLOCK_SIZE * BLOCK_SIZE);
	tile->desc[0]  = base[12];
	tile->desc[1]  = base[8];
	tile->desc[2]  = base[4];
	tile->desc[3]  = base[0];
	tile->desc[4]  = base[13];
	tile->desc[5]  = base[9];
	tile->desc[6]  = base[5];
	tile->desc[7]  = base[1];
	tile->desc[8]  = base[14];
	tile->desc[9]  = base[10];
	tile->desc[10] = base[6];
	tile->desc[11] = base[2];
	tile->desc[12] = base[15];
	tile->desc[13] = base[11];
	tile->desc[14] = base[7];
	tile->desc[15] = base[3];
	i = tile->mouse_x;
	tile->mouse_x = BLOCK_SIZE - 1 - tile->mouse_y;
	tile->mouse_y = i;
}

/** verifie que tous les carres entrent
 *
 * @param grid_pos: position su pointeur sur la grille
 * @param tile: forme a tester
 * @param grid: pointeur sur l'aire de jeu
 * @return: 0 si non posable
 *          1 si ok
 */
int is_placable(int grid_pos, struct tile_desc *tile, struct coord * grid){
	int j;   // position courante sur le tile
	int cur; // position courante sur la grille
	int x, y;  // position de depart sur la grille
	int tile_x, tile_y;

	// on prend les coordonees du premier carre
	cur = grid_pos - tile->mouse_x - ( tile->mouse_y * PAD_SIZE);
	
	// coordonéees du pointeur:
	x = ( grid_pos % PAD_SIZE ) - tile->mouse_x;
	y = ( grid_pos / PAD_SIZE ) - tile->mouse_y;
	
	// on verifie l'emplacement de tous les carres
	j = 0;
	tile_x = x;
	tile_y = y;
	while(j < BLOCK_SIZE * BLOCK_SIZE){

		// si le carre est plein, on le teste
		if(tile->desc[j] == 1 ||
		   tile->desc[j] == 2){
		
			// on est en dehors de la ligne
			if(tile_x < 0 || tile_x >= PAD_SIZE ||
			   tile_y < 0 || tile_y >= PAD_SIZE ){
				return 0;
			}
			
			// le tableau est occupe
			if(grid[cur].type != G_EMPTY){
				return 0;
			}
		}

		tile_x ++;
		if(tile_x == x + BLOCK_SIZE){
			tile_x = x;
			tile_y++;
			cur += ( PAD_SIZE - BLOCK_SIZE + 1 );
		} else {
			cur ++;
		}
		j ++;
	}
	return(1);
}

/**
 *
 * @return: 1 posable qq part
 *          0 non posable
 */
int is_any_placable(struct tile_desc *tile, struct coord * grid){
	int i, j;

	j = 0;
	while(j < 4){
		i = 0;
		while(i < PAD_SIZE * PAD_SIZE){
			if(is_placable(i, tile, grid)==1){
				return(1);
			}
			i++;
		}
		j++;
		rotate(tile);
	}
	return(0);
}
