#include "container.h"
#include "utils.h"

container *initialize_container(unsigned char type, unsigned long int original){
    container *c = malloc(sizeof(container));

    c->type = type;
    c->originalNbComponents = original;
    c->currentNbComponent = original;

    return c;
}

BOOL isContainerEmpty(container c){
    if(c.currentNbComponent == 0)
        return TRUE;
    else
        return FALSE;
}
