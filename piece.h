/* piece.h
 * Written by GUICHARD Meriadeg
 */

#ifndef PIECE_H
#define PIECE_H

/* Description of the file:
 *
 * This file specifies the definition of a primary composant
 */

typedef struct{
    short reference;
    char *name;
}piece;

piece* piece_initialisation(short ref, char *name);

#endif
