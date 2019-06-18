/*
 * operator.h
 * written by GUICHARD Mériadeg
 *
 * contains the difinition of the operators
 *
 */

#ifndef operator_H
#define operator_H

#include "utils.h"
#include "stock.h"

/* opérateur, se définit par:
 *  -un prénom
 *  -un numéro de poste
 *  -un nom de produit
 *  -un temps de production par produit
 *
 * On part du principe qu'un operateur ne fait que recevoir des produits des postes en amont,
 * qu'il ne sait que produire son type de produit, et qu'à chaque produit réalisé, il l'envoie
 * au poste suivant
 *
 * La synchronisation, le nombre de produits {A, B...} ainsi que le temps nécessaires pour produire un produit sont
 * gérés dans le programmes principal via une fonction dédiée, et sont modulables à l'éxécution de ce dernier.
 *
 * Dans un premier temps l'initalisation des opérateurs se fera via la création de leurs attributs principaux
 * Dans un second temps, on affectera "manuellement" à chaque opérateur les opérateurs *previous et *next.
 * L'emploi d'une liste chainée aurait été d'une part un peu trop lourd, et d'autre part, peu cohérente avec notre
 * vision du projet, en effet, les dépendences inter-postes ne sont pas linéaires, et l'emploi d'une liste chainée
 * aurait posé des soucis d'implémentation.
 *
 */
typedef struct Operateur{

    char *name; // the name of the operator, the length max is defined in utils.h
    char *productName; // the name of the product, the length is defined in utils.h

    unsigned short postNumber; // the number of the post
    unsigned long int productionTime; // the time an operator uses to create a product, in msec (that's why we use the unsigned long type)

    struct Operateur *prev1;
    struct Operateur *prev2;
    struct Operateur *next1;
    struct Operateur *next2;

    unsigned long int production;

    stock *stockO; // will only be instancied for the two first operators, will be NULL for the others
    BOOL has_container;

}operateur;

operateur *initialize_operator(char *name, unsigned short postNumber, unsigned long productionTime);

unsigned long int get_production(operateur *o);
unsigned long int take_production(operateur o);

void *fonc_operator(void *o);

void produire_operateur1(operateur o);
void produire_operateur2(operateur o);
void produire_operateur3(operateur o);
void produire_operateur4(operateur o);
void produire_operateur5(operateur o);
void produire_operateur6(operateur o);
void produire_operateur7(operateur o);


#endif //operator_H
