#include "container.h"
#include "utils.h"

container *initialize_container(char type, int orignal){
    container *c = malloc(sizeof(container));

    c->type = type;
    c->originalNbComponents = original;
    c->currentNbComponent = 0;

    return c;
}

BOOL isContainerEmpty(container c){
    if(c.currentNbComponent == 0)
        return TRUE;
    else
        return FALSE;
}
