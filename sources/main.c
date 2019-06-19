#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "../headers/utils.h"
#include "../headers/container.h"
#include "../headers/card.h"
#include "../headers/operator.h"
#include "../headers/stock.h"
#include "../headers/boite_aux_lettres.h"
#include "../headers/atelier.h"
#include "../headers/homme_flux.h"


int main(int argc, char** argv)
{
    /* TODO
     *
     * 1) ON AURA un nombre donné de containers, qui servira à créer le tableau de cartes de la boite aux lettres
     * 2)
     */
    int i, nbStocks = 2, nbContainers = 100, nbProductByContainer = 40000;
    boite = initialize_boite_aux_lettres();

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
    strcpy(operators_name[6], "EXPLOSION"); // assemble toutes les pièces pour créer le produit final

    homme_flux *f;
    operateur *operateurs = malloc(NB_OPERATORS * sizeof(operateur));
    for(i = 0; i != NB_OPERATORS; i++){
        operateur *o = initialize_operator(operators_name[i], i + 1, 2000000);
        operateurs[i] = *o;
    }

    /*operateurs[0].next1 = &operateurs[4];
    operateurs[0].next2 = &operateurs[5];
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
    operateurs[6].prev2 = &operateurs[5];*/

    operateurs[0].stockO = fiber;
    operateurs[1].stockO = plastic;

    /* Paramétrage de la synchronisation */

    // creation des threads opérateurs
    for(i = 0; i != NB_OPERATORS; i++)
        pthread_create(operators+i, NULL, fonc_operator, (void *)(&operateurs[i]));
    pthread_create(&flux, NULL, fonc_homme_flux, (void *)(f));

    // attends que la commande soit complétée
    for(i = 0; i != NB_OPERATORS; i++)
        pthread_join(operators[i], NULL);
    pthread_join(flux, NULL);


    /* end of the program */
    free(fiber);
    free(plastic);
    free(operateurs);

    return EXIT_SUCCESS;
}
