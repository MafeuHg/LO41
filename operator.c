
#include "operator.h"

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
        if(o.has_container == FALSE && o.stock->currentNbContainer > 0){
            usleep(50000);
            printf("L'operateur %s prend un container du stock de fibres\n", o.name);
            o.stock->currentNbContainer--;
            o.has_container = TRUE;
            c = initialize_container(o.stock->type, o.stock->nbProducts);
        }
        else if(o.has_container == FALSE && o.stock->currentNbContainer == 0){
            printf("Le stock de fibres etant vide, l'operateur %s attend de nouveaux containers\n", o.name);
            pthread_cond_signal(&fiberStock);
            pthread_mutex_lock(&mutex1);
            pthread_cond_wait(&wait1, &mutex1); // attend un signal indiquant
            pthread_mutex_unlock(&mutex1);
        }
        else{
            while(c->currentNbComponent > 0){
                if(c->currentNbComponent > 0){ // on va ajuster au nombre de matériaux requis pour un fil
                    usleep(o.productionTime); // temps requis pour produire 100 fils à partir de 400 fibres
                    c->currentNbComponent -= 400;
                    production_operator_1 += 200;
                    //pthread_cond_signal(&wait5);
                    //pthread_cond_signal(&wait6);
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
        if(o.has_container == FALSE && o.stock->currentNbContainer > 0){
            usleep(500000);
            printf("L'operateur %s prend un container du stock de plastique\n", o.name);
            o.stock->currentNbContainer--;
            o.has_container = TRUE;
            c = initialize_container(o.stock->type, o.stock->nbProducts);
        }
        else if(o.has_container == FALSE && o.stock->currentNbContainer == 0){
            printf("Le stock de plastique etant vide, l'operateur %s attend de nouveaux containers\n", o.name);
            pthread_cond_signal(&plasticStock);
            pthread_mutex_lock(&mutex2);
            pthread_cond_wait(&wait2, &mutex2);
            pthread_mutex_unlock(&mutex2);
        }
        else{
            while(c->currentNbComponent > 0){
                if(c->currentNbComponent > 0){ // on va ajuster au nombre de matériaux requis pour un fil
                    usleep(o.productionTime); // temps requis pour produire 100 fils à partir de 400 fibres
                    c->currentNbComponent -= 400;
                    production_operator_2 += 200;
                    printf("L'operateur %s a produit 200 bouts de plastique\n", o.name);
                    pthread_cond_signal(&wait3);
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
            usleep(1000000);
            printf("L'operateur %s a produit 1 oeil\n", o.name);
            production_operator_3 += 1;
        }
        /* TODO */
        /* On va faire en sorte de protéger la ressource critique "fibres" (car utilisée par deux opérateurs)
         * et faire pareil avec le plastique
         */
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
            usleep(1000000);
            printf("L'operateur %s a produit 1 bouton\n", o.name);
            production_operator_4 += 1;
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
        if(production_operator_1 >= 300){
            //production_operator_5_1 += 1;
            production_operator_1 -= 300;
            usleep(3500000);
            printf("L'operateur %s a produit un corps de poupee\n", o.name);

            pthread_cond_signal(&wait5_2);
            pthread_mutex_lock(&mutex5_1);
            pthread_cond_wait(&wait5_1, &mutex5_1);
            pthread_mutex_unlock(&mutex5_1);
        }
        else{
            //voir a bloquer ici et attendre un dernier signal de l'oprateur 1
        }
        if(production_operator_3 >= 2){
            pthread_mutex_lock(&mutex5_2);
            pthread_cond_wait(&wait5_2, &mutex5_2);
            pthread_mutex_unlock(&mutex5_2);

            production_operator_3 -= 2;
            production_operator_5_final += 1;
            printf("l'operateur %s a produit une poupee\n", o.name);
        }
        else{
            //voir a bloquer ici et attendre un dernier signal de l'oprateur 3
        }
    }

}
void produire_operateur6(operateur o){
    while(1){
        if(production_operator_1 >= 100){
            //production_operator_5_1 += 1;
            production_operator_1 -= 100;
            usleep(2500000);
            printf("L'operateur %s a produit un costume de poupee sans boutons\n", o.name);

            pthread_cond_signal(&wait6_2);
            pthread_mutex_lock(&mutex6_1);
            pthread_cond_wait(&wait6_1, &mutex6_1);
            pthread_mutex_unlock(&mutex6_1);
        }
        else{
            //voir a bloquer ici et attendre un dernier signal de l'oprateur 1
        }
        if(production_operator_4 >= 3){
            pthread_mutex_lock(&mutex6_2);
            pthread_cond_wait(&wait6_2, &mutex6_2);
            pthread_mutex_unlock(&mutex6_2);

            production_operator_4 -= 3;
            production_operator_6_final += 1;
            printf("l'operateur %s a produit un costume de poupee\n", o.name);
        }
        else{
            //voir a bloquer ici et attendre un dernier signal de l'oprateur 3
        }
    }


}
void produire_operateur7(operateur o){
    while(production_operator_7_final < 5){
        if(production_operator_5_final >= 1){
            //production_operator_5_1 += 1;
            production_operator_1 -= 1;
            usleep(1500000);

            pthread_cond_signal(&wait7_2);
            pthread_mutex_lock(&mutex7_1);
            pthread_cond_wait(&wait7_1, &mutex7_1);
            pthread_mutex_unlock(&mutex7_1);
        }
        else{
            //voir a bloquer ici et attendre un dernier signal de l'oprateur 1
        }
        if(production_operator_6_final >= 1){
            pthread_mutex_lock(&mutex7_2);
            pthread_cond_wait(&wait7_2, &mutex7_2);
            pthread_mutex_unlock(&mutex7_2);

            production_operator_5_final -= 1;
            production_operator_7_final += 1;
            printf("l'operateur %s a produit une poupee complete\n", o.name);
        }
        else{
            //voir a bloquer ici et attendre un dernier signal de l'oprateur 3
        }
    }


}
