#include "libs.h"
#include "pieces.h"

fibre* fibre_initialisation(short ref, char *name){
    fibre *p = malloc(sizeof(fibre));

    p->reference = ref;
    p->name = malloc(strlen(name) * sizeof(char));

    strcpy(p->name, name);

    return p;
}

fil* fil_initialisation(short ref, char *name){

}

tissu* tissu_initialisation(short ref, char *name){

}

costume* costume_initialisation(short ref, char *name){

}

corps* corps_initialisation(short ref, char *name){

}
