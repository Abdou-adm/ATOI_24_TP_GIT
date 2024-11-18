#ifndef PPM_H
#define PPM_H

/**
 * Structure représentant un pixel dans une image PPM.
 * Chaque pixel est composé de trois composantes : rouge (r), vert (g) et bleu (b).
 */
struct ppm_pixel {
  unsigned char r; ///< Intensité de la composante rouge (0-255)
  unsigned char g; ///< Intensité de la composante verte (0-255)
  unsigned char b; ///< Intensité de la composante bleue (0-255)
};

/**
 * Définit la valeur d'un pixel à partir de ses trois composantes.
 * @param px Pointeur vers le pixel
 * @param r Intensité de la composante rouge
 * @param g Intensité de la composante verte
 * @param b Intensité de la composante bleue
 */
static inline void ppm_setpixel(struct ppm_pixel *px, unsigned char r,
                                unsigned char g, unsigned char b) {
  px->r = r;
  px->g = g;
  px->b = b;
}

/**
 * Structure représentant une image PPM.
 * Contient les dimensions de l'image et un tableau de pixels.
 */
struct ppm_image {
  unsigned int width; ///< Largeur de l'image
  unsigned int height; ///< Hauteur de l'image
  struct ppm_pixel *px; ///< Tableau de pixels
};

/**
 * Initialise une image PPM en allouant de la mémoire pour les pixels.
 * @param im Pointeur vers l'image
 * @param w Largeur de l'image
 * @param h Hauteur de l'image
 * @return 0 si succès, 1 si échec
 */
int ppm_image_init(struct ppm_image *im, int w, int h);

/**
 * Libère la mémoire allouée pour une image PPM.
 * @param im Pointeur vers l'image
 * @return 0 si succès, 1 si échec
 */
int ppm_image_release(struct ppm_image *im);

/**
 * Sauvegarde une image PPM dans un fichier au format P6.
 * @param im Pointeur vers l'image
 * @param path Chemin du fichier de sortie
 * @return 0 si succès, 1 si échec
 */
int ppm_image_dump(struct ppm_image *im, char *path);

/**
 * Définit un pixel dans une image à partir de ses coordonnées (x, y).
 * @param im Pointeur vers l'image
 * @param x Coordonnée horizontale
 * @param y Coordonnée verticale
 * @param r Intensité de la composante rouge
 * @param g Intensité de la composante verte
 * @param b Intensité de la composante bleue
 */
static inline void ppm_image_setpixel(struct ppm_image *im, int x, int y,
                                      unsigned char r, unsigned char g,
                                      unsigned char b) {
  struct ppm_pixel *px = im->px + im->width * y + x;
  ppm_setpixel(px, r, g, b);
}

#endif /* PPM_H */
