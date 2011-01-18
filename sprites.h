/* colle l'image dans la buffer pret a sortir
 * x, y, src_x, src_y, width et height DOIVENT
 *   etre POSITIFS, aucun controle n'est fait !
 * @param img: image a coller
 * @param x, y: coordonée ou coller l'image
 * @param src_x, y: coordonnées de l'image source a partir de 
 *                  laquelle coller
 * @param width, height: longueur, hauteur a coller
 */
void put_image(struct vimg * aff,
               struct vimg * img,
               int x, int y,
               int src_x, int src_y,
               int width, int height);

/* applique un masque de transparence a une image
 * OxOO: tranparent
 * 0xff: opaque
 *
 * @param img: image a modifier
 * @param out: image de reception
 *             peut etre identique a la source
 *             doit pouvoir recevoir l'image
 * @param alpha: valeur alpha
 */
void set_alpha(struct vimg * img,
               struct vimg * out,
               unsigned char alpha);

/* colle l'image dans la buffer pret a sortir
 * x, y, src_x, src_y, width et height DOIVENT
 *   etre POSITIFS, aucun controle n'est fait !
 *
 * @param img: image a coller
 * @param x, y: coordonée ou coller l'image
 * @param src_x, y: coordonnées de l'image source a partir de 
 *                  laquelle coller
 * @param width, height: longueur, hauteur a coller
 */
void put_image_alpha(struct vimg * aff,
                     struct vimg * img,
                     int x, int y,
                     int src_x, int src_y,
                     int width, int height);
