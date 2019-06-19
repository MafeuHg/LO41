#include "../headers/operator.h"
#include "../headers/variables.h"
#include "../headers/boite_aux_lettres.h"

unsigned long int get_production(operateur *o){
    return o->production;
}

operateur *initialize_operator(char *name, unsigned short postNumber, unsigned long productionTime){

    operateur *o = malloc(sizeof(operateur));

    o->name = malloc(MAX_LENGTH_NAME * sizeof(char));
    o->productName = malloc(MAX_LENGTH_PRODUCT_NAME * sizeof(char));
    if(strlen(name) < MAX_LENGTH_NAME)
        strcpy(o->name, name);
    else
        strcpy(o->name, "operator");

    o->postNumber = postNumber;
    o->has_container = FALSE;
    o->productionTime = productionTime;

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
    while(1){
        if(o.has_container == FALSE && o.stockO->currentNbContainer > 0){
            usleep(50000);
            printf("L'operateur %s prend un container du stock de fibres\n", o.name);
            c = initialize_container(o.stockO->type, o.stockO->nbProducts, 1, 1, o.stockO->nbProducts, 3263825, 42, 6);
            add_card(c->mCard);
            o.stockO->currentNbContainer--;
            o.has_container = TRUE;
        }
        else if(o.has_container == FALSE && o.stockO->currentNbContainer == 0){
            printf("Le stock de fibres etant vide, l'operateur %s attend de nouveaux containers\n", o.name);
            pthread_mutex_lock(&mutex1);
            pthread_cond_wait(&fiberStock, &mutex1);
            pthread_mutex_unlock(&mutex1);
        }
        else{
            while(c->currentNbComponent > 0){
                if(c->currentNbComponent > 0){
                    usleep(o.productionTime);
                    c->currentNbComponent -= 400;
                    production_operator_1 += 200;
                    pthread_cond_signal(&wait5_1);
                    pthread_cond_signal(&wait6_1);
                    printf("L'operateur %s a produit 200 fils\n", o.name);
                }
            }
            printf("L'operateur %s a fini son container, il va en chercher un autre\n", o.name);
            o.has_container = FALSE;
        }
    }
}

void produire_operateur2(operateur o){
    container *c = NULL;
    while(1){
        if(o.has_container == FALSE && o.stockO->currentNbContainer > 0){
            usleep(500000);
            printf("L'operateur %s prend un container du stock de plastique\n", o.name);
            c = initialize_container(o.stockO->type, o.stockO->nbProducts, 2, 1, o.stockO->nbProducts, 3263827, 44, 13);
            add_card(c->mCard);
            o.stockO->currentNbContainer--;
            o.has_container = TRUE;
        }
        else if(o.has_container == FALSE && o.stockO->currentNbContainer == 0){
            printf("Le stock de plastique etant vide, l'operateur %s attend de nouveaux containers\n", o.name);
            pthread_mutex_lock(&mutex2);
            pthread_cond_wait(&plasticStock, &mutex2);
            pthread_mutex_unlock(&mutex2);
        }
        else{
            while(c->currentNbComponent > 0){
                if(c->currentNbComponent > 0){
                    usleep(2000000);
                    c->currentNbComponent -= 400;
                    production_operator_2 += 200;
                    printf("L'operateur %s a produit 200 bouts de plastique\n", o.name);
                    pthread_cond_signal(&wait3);
                    pthread_cond_signal(&wait4);
                }
            }
            printf("L'operateur %s a fini son container, il va en chercher un autre\n", o.name);
            o.has_container = FALSE;
        }
    }

}
void produire_operateur3(operateur o){
    while(1){
        if(production_operator_2 >= 100){
            production_operator_2 -= 100;
            usleep(3000000);
            production_operator_3 += 1;
            printf("L'operateur %s a produit 1 oeil\n", o.name);
            pthread_cond_signal(&wait5_2);
        }
        else if(production_operator_2 < 100){
            printf("L'operateur %s attend suffisamment de plastique pour produire des yeux\n", o.name);
            pthread_mutex_lock(&mutex3);
            pthread_cond_wait(&wait3, &mutex3);
            pthread_mutex_unlock(&mutex3);
        }

    }
}
void produire_operateur4(operateur o){
    while(1){
        if(production_operator_2 >= 100){
            production_operator_2 -= 100;
            usleep(2000000);
            printf("L'operateur %s a produit 1 bouton\n", o.name);
            production_operator_4 += 1;
            pthread_cond_signal(&wait6_2);
        }
        else if(production_operator_2 < 100){
            printf("L'operateur %s attend suffisamment de plastique pour produire des boutons\n", o.name);
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

        if(production_operator_1 >= 300){
            production_operator_1 -= 300;
            usleep(2500000);
            printf("L'operateur %s a fini un corps de poupee, il attend les yeux\n", o.name);

            pthread_mutex_lock(&mutex5_2);
            pthread_cond_wait(&wait5_2, &mutex5_2);
            pthread_mutex_unlock(&mutex5_2);
            if(production_operator_3 >= 2){
                production_operator_3 -= 2;
                usleep(1000000);
                production_operator_5 += 1;
                printf("L'operateur %s a fini de faire une poupee\n", o.name);
                pthread_cond_signal(&wait7_1);
            }
            else{
                printf("L'operateur %s attends des YEUX\n", o.name);

                pthread_mutex_lock(&mutex5_2);
                pthread_cond_wait(&wait5_2, &mutex5_2);
                pthread_mutex_unlock(&mutex5_2);
            }
        }
        else{
            printf("L'operateur %s attend des fils pour faire un corps de poupee\n", o.name);

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

        if(production_operator_1 >= 200){
            production_operator_1 -= 200;
            usleep(3500000);
            printf("L'operateur %s a fini un costume de poupee, il attends les boutons\n", o.name);

            pthread_mutex_lock(&mutex6_2);
            pthread_cond_wait(&wait6_2, &mutex6_2);
            pthread_mutex_unlock(&mutex6_2);
            if(production_operator_4 >= 3){
                production_operator_4 -= 3;
                usleep(1500000);
                production_operator_6 += 1;
                printf("L'operateur %s a fini de faire un costume de poupee\n", o.name);
                pthread_cond_signal(&wait7_2);
            }
            else{
                printf("L'operateur %s attends des BOUTONS\n", o.name);

                pthread_mutex_lock(&mutex6_2);
                pthread_cond_wait(&wait6_2, &mutex6_2);
                pthread_mutex_unlock(&mutex6_2);
            }

        }
        else{
            printf("L'operateur %s attend des fils pour faire un costume de poupee\n", o.name);

            pthread_mutex_lock(&mutex6_1);
            pthread_cond_wait(&wait6_1, &mutex6_1);
            pthread_mutex_unlock(&mutex6_1);
        }
    }
}
void produire_operateur7(operateur o){
    while(production_operator_7 < 3){

        pthread_mutex_lock(&mutex7_1);
        pthread_cond_wait(&wait7_1, &mutex7_1);
        pthread_mutex_unlock(&mutex7_1);

        if(production_operator_5 >= 1){
            production_operator_5 -= 1;
            usleep(100000);
            printf("L'operateur %s a recupere un corps, il attend le costume\n", o.name);

            pthread_mutex_lock(&mutex7_2);
            pthread_cond_wait(&wait7_2, &mutex7_2);
            pthread_mutex_unlock(&mutex7_2);

            if(production_operator_6 >= 1){
                production_operator_6 -= 1;
                usleep(100000);
                production_operator_7 += 1;
                printf("L'operateur %s a fini de faire  poupee COMPLETE\n", o.name);
                pthread_cond_signal(&wait7_2);
            }
            else{
                printf("L'operateur %s attends un COSTUME\n", o.name);

                pthread_mutex_lock(&mutex7_2);
                pthread_cond_wait(&wait7_2, &mutex7_2);
                pthread_mutex_unlock(&mutex7_2);
            }

        }
        else{
            printf("L'operateur %s attend une poupee\n", o.name);

            pthread_mutex_lock(&mutex7_1);
            pthread_cond_wait(&wait7_1, &mutex7_1);
            pthread_mutex_unlock(&mutex7_1);
        }
    }
    printf("La commande est finie, circulez !\n");
    exit(EXIT_SUCCESS);
}
