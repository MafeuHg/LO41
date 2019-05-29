/* piece.h
 * Written by GUICHARD Meriadeg
 */

#ifndef PIECE_H
#define PIECE_H

/* Description of the file:
 *
 * This file specifies the definition of the primary composants to create a product
 * such as a dolls that looks like Jacques Chirac.
 */

typedef struct{
    short reference;
    char *name;
}fibre;

typedef struct{
    short reference;
    char *name;

    /* The numbers of fibers required to create a piece of fil */
    int nbFibres;
}fil;

typedef struct{
    short reference;
    char *name;

    /* The numbers of fils required to create a piece of tissu */
    int nbFils
}tissu;

typedef struct{
    short reference;
    char *name;

    /* The numbers of fils required to create a costume */
    int nbTissus;
}costume;

typedef struct{
    short reference;
    char *name;

    int nbFils;
    int nbTissus;
}corps;

fibre* fibre_initialisation(short ref, char *name);
fil* fil_initialisation(short ref, char *name), int nbF;
tissu* tissu_initialisation(short ref, char *name, int nbFi);
costume* costume_initialisation(short ref, char *name, int nbT, int nbFi);
corps* corps_initialisation(short ref, char *name, int nbFi, int nbT);

#endif
