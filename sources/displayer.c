#include "./../headers/utils.h"
#include "./../headers/utils.h"
#include "./../headers/operator.h"

displayer *initialize_displayer(char **list){
    int i;

    displayer *disp = malloc(sizeof(displayer));
    disp->product_names = malloc(NB_OPERATORS * MAX_LENGTH_PRODUCT_NAME * sizeof(char));

    if(disp->product_names == NULL){
        perror("Erreur d'allocation de premier rang de product_names");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i != NB_OPERATORS; i++){
        disp->product_names[i] = malloc(MAX_LENGTH_PRODUCT_NAME * sizeof(char));
        if(disp->product_names[i] == NULL){
            perror("Erreur d'allocation de deuxieme rang de product_names");
            exit(EXIT_FAILURE);
        }
    }

    for(i = 0; i != NB_OPERATORS; i++){
        strcpy(disp->product_names[i], list[i]);
    }

    return disp;
}

void *displayyy(void *d){

    displayer *disp = d;
    while(1){
        printf("\e[1;1H\e[2J");
        printf("EXPLOSION\n");

        usleep(1500000);
    }
}
