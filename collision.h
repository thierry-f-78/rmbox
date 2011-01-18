/** verifie que tous les carres entrent
 *
 * @param grid_pos: position su pointeur sur la grille
 * @param tile: forme a tester
 * @param grid: pointeur sur l'aire de jeu
 * @return: 0 si non posable
 *          1 si ok
 */
int is_placable(int grid_pos, struct tile_desc *tile, struct coord * grid);

void rotate(struct tile_desc *tile);
