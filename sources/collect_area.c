#include "../headers/collect_area.h"

void *fonct_collect_area(void *d){
    collect_area *ca = d;

    while(1){
        if(ca->nbContainer > 0)
            pthread_cond_signal(collect_area_wait);
    }
}
