#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "utils.h"
#include "container.h"
#include "card.h"
#include "operator.h"
#include "stock.h"


int main(int argc, char** argv)
{
    int i, nbStocks = 2, nbContainers = 100, nbProductByContainer = 40000;

    /* Stock initialisation */
    stock *fiber = initalize_stock(nbContainers, 'f', nbProductByContainer);
    stock *plastic = initalize_stock(nbContainers, 'p', nbProductByContainer);

    /* Operators initialisation */
    char operators_name[NB_OPERATORS][MAX_LENGTH_NAME];
    strcpy(operators_name[0], "Jean Michel"); // crée des fils
    strcpy(operators_name[1], "Francky"); // crée du plastique utilisable
    strcpy(operators_name[2], "Jacky"); // crée des yeux en plastique
    strcpy(operators_name[3], "Djadja"); // crée des boutons de costume
    strcpy(operators_name[4], "Monocle"); // crée le corps de la poupée
    strcpy(operators_name[5], "Edouard"); // crée le costume de la poupée
    strcpy(operators_name[6], "Dupond"); // assemble toutes les pièces pour créer le produit final

    operateur *operateurs = malloc(NB_OPERATORS * sizeof(operateur));
    for(i = 0; i != NB_OPERATORS; i++){
        operateur *o = initialize_operator(operators_name[i], i + 1, 2000000);
        operateurs[i] = *o;
    }

    /* paramétrage des opérateurs */

    operateurs[0].stock = fiber;
    operateurs[0].next1 = &operateurs[4];
    operateurs[0].next2 = &operateurs[5];

    operateurs[1].stock = plastic;
    operateurs[1].next1 = &operateurs[2];
    operateurs[1].next2 = &operateurs[3];

    operateurs[2].prev1 = &operateurs[1];
    operateurs[2].next1 = &operateurs[4];

    operateurs[3].prev1 = &operateurs[1];
    operateurs[3].next1 = &operateurs[5];

    operateurs[4].prev1 = &operateurs[0];
    operateurs[4].prev2 = &operateurs[2];
    operateurs[4].next1 = &operateurs[6];

    operateurs[5].prev1 = &operateurs[0];
    operateurs[5].prev2 = &operateurs[3];
    operateurs[5].next1 = &operateurs[6];

    operateurs[6].prev1 = &operateurs[4];
    operateurs[6].prev2 = &operateurs[5];

    /* Paramétrage de la synchronisation */

    printf("%s et %s\n", operateurs[2].name, operateurs[2].prev1->name);
    // creation des threads opérateurs
    for(i = 0; i != 3; i++)
        pthread_create(operators+i, NULL, fonc_operator, (void *)(&operateurs[i]));

    // attends que la commande soit complétée
    for(i = 0; i != 3; i++)
        pthread_join(operators[i], NULL);


    /* end of the program */
    free(fiber);
    free(plastic);
    free(operateurs);

    return EXIT_SUCCESS;
}
