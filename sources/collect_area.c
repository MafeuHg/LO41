#include "../headers/collect_area.h"
#include "../headers/utils.h"

collect_area *initialize_collect_area(){
    collect_area *ca = malloc(sizeof(collect_area));
    ca->nbContainer = 0;

    return ca;
}

void *fonc_collect_area(void *d){
    collect_area *ca = d;

    while(1){
        if(ca->nbContainer > 0)
            pthread_cond_signal(&waiting_for_cont);
    }
}
