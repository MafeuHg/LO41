#include "libs.h"

piece piece_initialisation(short ref, char *name){
    piece *p = malloc(sizeof(piece));

    p->reference = ref;
    p->name = malloc(strlen(name) * sizeof(char));

    strcpy(p->name, name);

    return piece;
}
