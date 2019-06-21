#include "../headers/operator.h"
#include "../headers/productions.h"
#include "../headers/collect_area.h"

operateur *initialize_operator(char *name, char *product_name, unsigned short postNumber, unsigned long productionTime, collect_area *ca, boite_aux_lettres *b){

    operateur *o = malloc(sizeof(operateur));

    o->name = malloc(MAX_LENGTH_NAME * sizeof(char));
    if(strlen(name) < MAX_LENGTH_NAME)
        strcpy(o->name, name);
    else
        strcpy(o->name, "operator");

    o->productName = malloc(MAX_LENGTH_PRODUCT_NAME * sizeof(char));
    if(strlen(product_name) < MAX_LENGTH_NAME)
        strcpy(o->productName, product_name);
    else
        strcpy(o->name, "invalid product name");

    o->postNumber = postNumber;
    o->has_container = FALSE;
    o->productionTime = productionTime;
    o->collect_zone = ca;
    o->boite = b;

    return o;
}

void *fonc_operator(void *o){
    operateur *op = o;

    switch(op->postNumber){
        case 1:
                produire_operateur1(*op);
        case 2:
                produire_operateur2(*op);
        case 3:
                produire_operateur3(*op);
        case 4:
                produire_operateur4(*op);
        case 5:
                produire_operateur5(*op);
        case 6:
                produire_operateur6(*op);
        case 7:
                produire_operateur7(*op);
    }
}

void produire_operateur1(operateur o){
    container *c = NULL;
    int reste = 0;

    while(1){
        if(o.has_container == FALSE && o.stock->currentNbContainer > 0){
            usleep(3000000);
            printf("L'operateur %s prend un container du stock de fibres\n", o.name);
            o.stock->currentNbContainer--;
            c = container_initialize(o.stock->type, o.stock->nbProducts + reste, 1, 1, o.stock->nbProducts, 3263825, 42, 6);
            reste = 0;
            add_card(o.boite, c->mCard);
            o.has_container = TRUE;
        }
        else if(o.has_container == FALSE && o.stock->currentNbContainer <= 0){
            printf("Le stock de fibres etant vide, l'operateur %s attend de nouveaux containers\n", o.name);
            pthread_mutex_lock(&mutex1);
            pthread_cond_wait(&wait1, &mutex1);
            pthread_mutex_unlock(&mutex1);
        }
        else{
            while(c->currentNbComponent > 0){
                if(c->currentNbComponent - OPERATOR_1_NB_PRODUCT_REQUIRED < 0){
                    reste = c->currentNbComponent;
                    c->currentNbComponent = 0;
                }
                else{
                    usleep(2500000);
                    c->currentNbComponent -= OPERATOR_1_NB_PRODUCT_REQUIRED;
                    production_operator_1 += QUANTITY_OPERATOR_1;
                    display(o);
                    pthread_cond_signal(&wait5_1);
                    pthread_cond_signal(&wait6_1);
                }
            }
            printf("L'operateur %s a fini son container\n", o.name);
            o.collect_zone->nbContainer++;
            pthread_cond_signal(&waiting_for_cont);
            o.has_container = FALSE;
        }
    }
}

void produire_operateur2(operateur o){
    container *c = NULL;
    int reste = 0;

    while(1){
        if(o.has_container == FALSE && o.stock->currentNbContainer > 0){
            usleep(3500000);
            printf("L'operateur %s prend un container du stock de plastique\n", o.name);
            c = container_initialize(o.stock->type, o.stock->nbProducts + reste, 2, 1, o.stock->nbProducts, 3263827, 44, 13);
            reste = 0;
            add_card(o.boite, c->mCard);
            o.stock->currentNbContainer--;
            o.has_container = TRUE;
        }
        else if(o.has_container == FALSE && o.stock->currentNbContainer == 0){
            printf("Le stock de plastique etant vide, l'operateur %s attend de nouveaux containers\n", o.name);
            pthread_mutex_lock(&mutex2);
            pthread_cond_wait(&wait2, &mutex2);
            pthread_mutex_unlock(&mutex2);
        }
        else{
            while(c->currentNbComponent > 0){
                if(c->currentNbComponent - OPERATOR_2_NB_PRODUCT_REQUIRED < 0){
                    reste = c->currentNbComponent;
                    c->currentNbComponent = 0;
                }
                else{
                    usleep(3500000);
                    c->currentNbComponent -= OPERATOR_2_NB_PRODUCT_REQUIRED;
                    production_operator_2 += QUANTITY_OPERATOR_2;
                    display(o);
                    pthread_cond_signal(&wait3);
                    pthread_cond_signal(&wait4);
                }
            }
            //printf("L'operateur %s a fini son container\n", o.name);
            o.collect_zone->nbContainer++;
            pthread_cond_signal(&waiting_for_cont);
            o.has_container = FALSE;
        }
    }

}
void produire_operateur3(operateur o){
    while(1){
        if(production_operator_2 >= OPERATOR_3_NB_PRODUCT_REQUIRED){
            production_operator_2 -= OPERATOR_3_NB_PRODUCT_REQUIRED;
            usleep(2000000);
            production_operator_3 += QUANTITY_OPERATOR_3;
            display(o);
            pthread_cond_signal(&wait5_2);
        }
        else if(production_operator_2 < OPERATOR_3_NB_PRODUCT_REQUIRED){
            //printf("\tL'operateur %s attend du plastique\n", o.name);
            pthread_mutex_lock(&mutex3);
            pthread_cond_wait(&wait3, &mutex3);
            pthread_mutex_unlock(&mutex3);
        }

    }
}
void produire_operateur4(operateur o){
    while(1){
        if(production_operator_2 >= OPERATOR_4_NB_PRODUCT_REQUIRED){
            production_operator_2 -= OPERATOR_4_NB_PRODUCT_REQUIRED;
            usleep(4000000);
            display(o);
            production_operator_4 += QUANTITY_OPERATOR_4;
            pthread_cond_signal(&wait6_2);
        }
        else if(production_operator_2 < OPERATOR_4_NB_PRODUCT_REQUIRED){
            //printf("\tL'operateur %s attend du plastique\n", o.name);
            pthread_mutex_lock(&mutex4);
            pthread_cond_wait(&wait4, &mutex4);
            pthread_mutex_unlock(&mutex4);
        }
    }
}
void produire_operateur5(operateur o){
    while(1){

        pthread_mutex_lock(&mutex5_1);
        pthread_cond_wait(&wait5_1, &mutex5_1);
        pthread_mutex_unlock(&mutex5_1);

        if(production_operator_1 >= OPERATOR_5_NB_PRODUCT_1_REQUIRED){
            production_operator_1 -= OPERATOR_5_NB_PRODUCT_1_REQUIRED;
            usleep(2500000);

            pthread_mutex_lock(&mutex5_2);
            pthread_cond_wait(&wait5_2, &mutex5_2);
            pthread_mutex_unlock(&mutex5_2);
            if(production_operator_3 >= OPERATOR_5_NB_PRODUCT_2_REQUIRED){
                production_operator_3 -= OPERATOR_5_NB_PRODUCT_2_REQUIRED;
                usleep(3000000);
                production_operator_5 += QUANTITY_OPERATOR_5;
                display(o);
                pthread_cond_signal(&wait7_1);
            }
            else{
                //printf("\t\tL'operateur %s attends des yeux\n", o.name);

                pthread_mutex_lock(&mutex5_2);
                pthread_cond_wait(&wait5_2, &mutex5_2);
                pthread_mutex_unlock(&mutex5_2);
            }
        }
        else{
            //printf("\t\tL'operateur %s attend des fils\n", o.name);

            pthread_mutex_lock(&mutex5_1);
            pthread_cond_wait(&wait5_1, &mutex5_1);
            pthread_mutex_unlock(&mutex5_1);
        }
    }

}
void produire_operateur6(operateur o){
    while(1){

        pthread_mutex_lock(&mutex6_1);
        pthread_cond_wait(&wait6_1, &mutex6_1);
        pthread_mutex_unlock(&mutex6_1);

        if(production_operator_1 >= OPERATOR_6_NB_PRODUCT_1_REQUIRED){
            production_operator_1 -= OPERATOR_6_NB_PRODUCT_1_REQUIRED;
            usleep(3500000);

            pthread_mutex_lock(&mutex6_2);
            pthread_cond_wait(&wait6_2, &mutex6_2);
            pthread_mutex_unlock(&mutex6_2);
            if(production_operator_4 >= OPERATOR_6_NB_PRODUCT_2_REQUIRED){
                production_operator_4 -= OPERATOR_6_NB_PRODUCT_2_REQUIRED;
                usleep(1500000);
                production_operator_6 += QUANTITY_OPERATOR_6;
                display(o);
                pthread_cond_signal(&wait7_2);
            }
            else{
                //printf("\t\tL'operateur %s attends des boutons\n", o.name);

                pthread_mutex_lock(&mutex6_2);
                pthread_cond_wait(&wait6_2, &mutex6_2);
                pthread_mutex_unlock(&mutex6_2);
            }

        }
        else{
            //printf("\t\tL'operateur %s attend des fils\n", o.name);

            pthread_mutex_lock(&mutex6_1);
            pthread_cond_wait(&wait6_1, &mutex6_1);
            pthread_mutex_unlock(&mutex6_1);
        }
    }
}
void produire_operateur7(operateur o){
    while(production_operator_7 < o.nb_final_product){

        pthread_mutex_lock(&mutex7_1);
        pthread_cond_wait(&wait7_1, &mutex7_1);
        pthread_mutex_unlock(&mutex7_1);

        if(production_operator_5 >= OPERATOR_7_NB_PRODUCT_1_REQUIRED){
            production_operator_5 -= OPERATOR_7_NB_PRODUCT_1_REQUIRED;
            usleep(100000);

            pthread_mutex_lock(&mutex7_2);
            pthread_cond_wait(&wait7_2, &mutex7_2);
            pthread_mutex_unlock(&mutex7_2);

            if(production_operator_6 >= OPERATOR_7_NB_PRODUCT_2_REQUIRED){
                production_operator_6 -= OPERATOR_7_NB_PRODUCT_2_REQUIRED;
                usleep(2700000);
                production_operator_7 += QUANTITY_OPERATOR_7;
                display(o);
                pthread_cond_signal(&wait7_2);
            }
            else{

                pthread_mutex_lock(&mutex7_2);
                pthread_cond_wait(&wait7_2, &mutex7_2);
                pthread_mutex_unlock(&mutex7_2);
            }

        }
        else{
            //printf("L'operateur %s attend une poupee\n", o.name);

            pthread_mutex_lock(&mutex7_1);
            pthread_cond_wait(&wait7_1, &mutex7_1);
            pthread_mutex_unlock(&mutex7_1);
        }
    }
    printf("La commande est finie.\n");
    exit(EXIT_SUCCESS);
}

void display(operateur o){
    switch(o.postNumber){
        case 1:
            printf("Operateur %s: %i %s\n", o.name, QUANTITY_OPERATOR_1, o.productName);
            break;
        case 2:
            printf("Operateur %s: %i %s\n", o.name, QUANTITY_OPERATOR_1, o.productName);
            break;
        case 3:
            printf("\t\tOperateur %s: %i %s\n", o.name, QUANTITY_OPERATOR_1, o.productName);
            break;
        case 4:
            printf("\t\tOperateur %s: %i %s\n", o.name, QUANTITY_OPERATOR_1, o.productName);
            break;
        case 5:
            printf("\t\t\tOperateur %s: %i %s\n", o.name, QUANTITY_OPERATOR_1, o.productName);
            break;
        case 6:
            printf("\t\t\tOperateur %s: %i %s\n", o.name, QUANTITY_OPERATOR_1, o.productName);
            break;
        case 7:
            printf("\t\t\t\tOperateur %s: %i %s\n", o.name, QUANTITY_OPERATOR_1, o.productName);
            break;
    }
}
