#include "libs.h"
#include "pieces.h"

/* TODO
 * Try to get the name directly, without any dynamic allocation
 */

fibre* fibre_initialisation(short ref, char *name){
    fibre *p = malloc(sizeof(fibre));

    p->reference = ref;
    p->name = malloc(strlen(name) * sizeof(char));

    strcpy(p->name, name);

    return p;
}

fil* fil_initialisation(short ref, char *name, int nbF){
    fil *f = malloc(sizeof(fil));

    f->reference = ref;
    f->name = malloc(strlen(name) * sizeof(char));
    f->nbFils = nb;

    strcpy(f->name, name);

    return f;
}

tissu* tissu_initialisation(short ref, char *name, int nbFi){
    tissu *t = malloc(sizeof(tissu));
    t->name = malloc(strlen(name) * sizeof(char));

    t->reference = ref;
    strcpy(t->name, name);
    t->nbFils = nbFi;

    return t;
}

costume* costume_initialisation(short ref, char *name, int nbFi, int nbT){
    costume *cos = malloc(sizeof(costume));
    cos->name = malloc(strlen(name) * sizeof(char));

    cos->reference = ref;
    cos->nbFils = nbFi;
    cos->nbTissus = nbT;
    strcpy(cos->name, name);

    return cos;
}

corps* corps_initialisation(short ref, char *name, int nbFi, int nbT){
    corps *co = malloc(sizeof(costume));
    co->name = malloc(strlen(name) * sizeof(char));

    co->reference = ref;
    co->nbFils = nbFi;
    co->nbTissus = nbT;
    strcpy(co->name, name);

    return co;
}
