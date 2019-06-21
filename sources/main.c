/*
 * main.c
 * written by GUICHARD Mériadeg
 *
 * contains the instanciation of the main program's elements
 * Manages the intitialisation and the synchronization of those
 * elements
 *
 */

#include "../headers/utils.h"
#include "../headers/container.h"
#include "../headers/card.h"
#include "../headers/operator.h"
#include "../headers/stock.h"
#include "../headers/boite_aux_lettres.h"
#include "../headers/atelier.h"
#include "../headers/homme_flux.h"
#include "../headers/collect_area.h"


/*
 * function: initialization
 * description: manages the initialization of the entities that will run the program
 * as descripted below:
 *
 *      1) run of the initialization functions
 *      2) assignation of the operator's names
 *      3)
 *
 */
void initialization(int nb_product_final, char *final_product_name);

/*
 * function: synchronization
 * description: manages the synchronisation of the entities that will run the program
 * as descripted below:
 *
 *      1) Creation of the differents threads
 *      2) Execution of those threads
 *      3) Association between operators 1, 2 and the stocks of fiber and plastic
 *
 */
void synchronization(operateur *operateurs, homme_flux *hf, collect_area *collect_zone, stock *fiber, stock *plastic);

int main(int argc, char *argv[]){

    int nb_product_final = 0;
    char *final_product_name = "Poupees geantes a l'effigie de Jacques Chirac";

    printf("Bonjour, combien voulez vous produire de %s: ", final_product_name);
    scanf("%d", & nb_product_final);
    printf("\e[1;1H\e[2J");

    initialization(nb_product_final, final_product_name);
    return EXIT_SUCCESS;
}


void initialization(int nb_product_final, char *final_product_name)
{
     /*
     * The numerical values used to the initializarion
     *
     * i: iterative variable
     * nbStocks: the number of stocks presents in the factory
     * nbContainers: the number of containers per stocks
     * nbProductByContainer: the number of product in each container
     * operators_name: an array of string that containes the names of the operators
     *
     */
    int i;
    int nbStocks = 2;
    int nbContainers = 100;
    int nbProductByContainer = 2000;
    char operators_name[NB_OPERATORS][MAX_LENGTH_NAME];
    char product_names[NB_OPERATORS][MAX_LENGTH_PRODUCT_NAME];


    /*
     * The entities that will be managed during the program
     * the description of each identity is provided in the corresponding
     * .h files
     *
     * hf: the homme_flux entity
     * at: the factory entity
     * collect_zone: the collection_area entity
     * boite: the boite_aux_lettres entity
     * display: the displayer entity
     *
     */
    boite_aux_lettres *boite = initialize_boite_aux_lettres();
    collect_area *collect_zone = initialize_collect_area();
    homme_flux *hf = homme_flux_intialize(boite);
    atelier *at = initialize_atelier(hf);
    stock *fiber = initalize_stock(nbContainers, 'f', nbProductByContainer, collect_zone);
    stock *plastic = initalize_stock(nbContainers, 'p', nbProductByContainer, collect_zone);

    /* Operators names and product names initialisation */
    strcpy(operators_name[0], "Jean Michel"); // crée des fils
    strcpy(operators_name[1], "Francky"); // crée du plastique utilisable
    strcpy(operators_name[2], "Jacky"); // crée des yeux en plastique
    strcpy(operators_name[3], "Vincent"); // crée des boutons de costume
    strcpy(operators_name[4], "Dark Vador"); // crée le corps de la poupée
    strcpy(operators_name[5], "Jacques Pereira"); // crée le costume de la poupée
    strcpy(operators_name[6], "Lee"); // assemble toutes les pièces pour créer le produit final

    strcpy(product_names[0], "Fils");
    strcpy(product_names[1], "Plastique");
    strcpy(product_names[2], "Oeil");
    strcpy(product_names[3], "Boutons");
    strcpy(product_names[4], "Corps de poupee");
    strcpy(product_names[5], "Costume de poupee");
    strcpy(product_names[6], final_product_name);


    /* Initialisation of the array of operators */
    operateur *operateurs = malloc(NB_OPERATORS * sizeof(operateur));
    for(i = 0; i != NB_OPERATORS; i++){
        operateur *o = initialize_operator(operators_name[i], product_names[i], i + 1, 2000000, collect_zone, boite);
        operateurs[i] = *o;
    }

    /* Assignation of the stocks required by the operatos */
    operateurs[0].stock = fiber;
    operateurs[1].stock = plastic;
    operateurs[6].nb_final_product = nb_product_final;

    /* Call to the synchronization function */
    synchronization(operateurs, hf, collect_zone, fiber, plastic);
}


void synchronization(operateur *operateurs, homme_flux *hf, collect_area *collect_zone, stock *fiber, stock *plastic){
    int i;

    /* Operators thread creation */
    for(i = 0; i != NB_OPERATORS; i++)
        pthread_create(operators+i, NULL, fonc_operator, (void *)(&operateurs[i]));

    /* Homme flux's thread creation */
    pthread_create(&homme_flux_thread, NULL, fonc_homme_flux, (void *)(hf));

    /* Collect area's thread creation */
    pthread_create(&collect_area_thread, NULL, fonc_collect_area, (void *)(collect_zone));

    /* Factory's thread creation */
    pthread_create(&atelier_thread, NULL, fonc_atelier, (void *)(hf));

    /* Stocks threads creation */
    pthread_create(&fiber_stock, NULL, fonc_fiberStock, (void *)(fiber));
    pthread_create(&plastic_stock, NULL, fonc_plasticStock, (void *)(plastic));


    /* Now we run the previously created threads in the order below:
     *      1) collect area
     *      2) homme flux
     *      3) factory
     *      4) stocks
     *      5) operators
     *
     * The order was choosed to avoid some threads that requires ressources of other threads that are not running
     * to create some problems such as seg.fault
     */
    pthread_join(collect_area_thread, NULL);
    pthread_join(homme_flux_thread, NULL);
    pthread_join(atelier_thread, NULL);
    pthread_join(fiber_stock,NULL);
    pthread_join(plastic_stock, NULL);

    for(i = 0; i != NB_OPERATORS; i++)
        pthread_join(operators[i], NULL);

}
