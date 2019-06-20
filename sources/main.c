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
#include "../headers/collect_area.h"


int main(int argc, char** argv)
{
    int i, nbStocks = 2, nbContainers = 100, nbProductByContainer = 10000;
    boite = initialize_boite_aux_lettres();
    homme_flux *hf = homme_flux_intialize();
    atelier *at = initialize_atelier(hf);
    collect_zone = initialize_collect_area();

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

    //homme_flux *f;
    operateur *operateurs = malloc(NB_OPERATORS * sizeof(operateur));
    for(i = 0; i != NB_OPERATORS; i++){
        operateur *o = initialize_operator(operators_name[i], i + 1, 2000000);
        operateurs[i] = *o;
    }

    operateurs[0].stockO = fiber;
    operateurs[1].stockO = plastic;
    operateurs[6].stockO = fiber;
    operateurs[6].stock1 = plastic;

    /* Paramétrage de la synchronisation */

    // creation des threads opérateurs
    for(i = 0; i != NB_OPERATORS; i++)
        pthread_create(operators+i, NULL, fonc_operator, (void *)(&operateurs[i]));

    // Creation du thread homme flux
    pthread_create(&homme_flux_thread, NULL, fonc_homme_flux, (void *)(hf));

    // Creation du thread zone de collecte
    pthread_create(&collect_area_thread, NULL, fonc_collect_area, (void *)(collect_zone));

    // Creation du thread atelier
    pthread_create(&atelier_thread, NULL, fonc_atelier, (void *)(hf));

    // Creation des threads des stocks
    pthread_create(&fiber_stock, NULL, fonc_fiberStock, (void *)(fiber));
    pthread_create(&plastic_stock, NULL, fonc_plasticStock, (void *)(plastic));

    // attends que la commande soit complétée
    pthread_join(collect_area_thread, NULL);
    pthread_join(homme_flux_thread, NULL);
    pthread_join(atelier_thread, NULL);
    pthread_join(fiber_stock,NULL);
    pthread_join(plastic_stock, NULL);
    for(i = 0; i != NB_OPERATORS; i++)
        pthread_join(operators[i], NULL);



    /* end of the program */
    free(fiber);
    free(plastic);
    free(operateurs);

    return EXIT_SUCCESS;
}
