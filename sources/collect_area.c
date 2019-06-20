#include "../headers/collect_area.h"

collect_area *initialize_collect_area(){
    collect_area *ca = malloc(sizeof(collect_area));
    ca->nbContainer = 0;

    return ca;
}

void *fonc_collect_area(void *d){
    collect_area *ca = d;

    while(1){
        pthread_mutex_lock(&collect_area_mutex);
        pthread_cond_wait(&collect_area_wait, &collect_area_mutex);
        pthread_mutex_unlock(&collect_area_mutex);

        pthread_cond_signal(&waiting_for_cont);
    }
}
