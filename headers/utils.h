#ifndef UTILS_H
#define UTILS_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define MAX_LENGTH_NAME 127
#define MAX_LENGTH_PRODUCT_NAME 50
#define NB_OPERATORS 7
#define FINAL_PRODUCT_NAME "Poupees geantes a l'effigie de Jacques Chirac"

/*
 * Here is the definition of each quantity required by an operator to produce the quantity defined below
 *
 */
#define OPERATOR_1_NB_PRODUCT_REQUIRED 400
#define OPERATOR_2_NB_PRODUCT_REQUIRED 400
#define OPERATOR_3_NB_PRODUCT_REQUIRED 100
#define OPERATOR_4_NB_PRODUCT_REQUIRED 100
#define OPERATOR_5_NB_PRODUCT_1_REQUIRED 300
#define OPERATOR_5_NB_PRODUCT_2_REQUIRED 2
#define OPERATOR_6_NB_PRODUCT_1_REQUIRED 200
#define OPERATOR_6_NB_PRODUCT_2_REQUIRED 3
#define OPERATOR_7_NB_PRODUCT_1_REQUIRED 1
#define OPERATOR_7_NB_PRODUCT_2_REQUIRED 1

/*
 * Here is the definition of each quantity of a product created by an operator
 *
 */
#define QUANTITY_OPERATOR_1 200
#define QUANTITY_OPERATOR_2 200
#define QUANTITY_OPERATOR_3 1
#define QUANTITY_OPERATOR_4 1
#define QUANTITY_OPERATOR_5 1
#define QUANTITY_OPERATOR_6 1
#define QUANTITY_OPERATOR_7 1


/*
 * SYNCHRONIZATION ELEMENTS: Description
 *
 * this section contains the difintions of the differents mutexes, conditions and threads
 * that manage the program's synchronization.
 * They are at a global scope in order to be used by the differents elements of the program
 *
 * They are organized as follow:
 *      1) operators
 *      2) stocks
 *      3) factory
 *      4) homme flux
 *      5) boite aux lettres
 *      6) collect area
 *      7) display
 */

/*
 * SYNCHRONIZATION ELEMENTS: Operators
 *
 */
/* operators threads */
pthread_t operators[NB_OPERATORS];
/* operators conditions */
pthread_cond_t wait1;
pthread_cond_t wait2;
pthread_cond_t wait3;
pthread_cond_t wait4;
pthread_cond_t wait5_1;
pthread_cond_t wait5_2;
pthread_cond_t wait6_1;
pthread_cond_t wait6_2;
pthread_cond_t wait7_1;
pthread_cond_t wait7_2;
/* operators mutexes */
pthread_mutex_t mutex1;
pthread_mutex_t mutex2;
pthread_mutex_t mutex3;
pthread_mutex_t mutex4;
pthread_mutex_t mutex5_1;
pthread_mutex_t mutex5_2;
pthread_mutex_t mutex6_1;
pthread_mutex_t mutex6_2;
pthread_mutex_t mutex7_1;
pthread_mutex_t mutex7_2;


/*
 * SYNCHRONIZATION ELEMENTS: Stocks
 *
 */
/* stocks threads */
pthread_t fiber_stock;
pthread_t plastic_stock;
/* stocks conditions */
pthread_cond_t waitFiber;
pthread_cond_t waitPlastic;
/* stocks mutex */
pthread_mutex_t fiberStock;
pthread_mutex_t plasticStock;


/*
 * SYNCHRONIZATION ELEMENTS: Factory
 *
 */
/* factory threads */
pthread_t atelier_thread;
/* factory conditions */
pthread_cond_t fiberOrder;
pthread_cond_t plasticOrder;
pthread_cond_t wait_atelier;
/* factory mutex */
pthread_mutex_t mutex_atelier;


/*
 * SYNCHRONIZATION ELEMENTS: Homme flux
 *
 */
/* Threads used by the differents entities */
/* homme flux thread */
pthread_t homme_flux_thread;
/* homme flux mutex */
pthread_mutex_t homme_flux_mutex;


/*
 * SYNCHRONIZATION ELEMENTS: Boite aux lettres
 *
 */
/* boite aux lettres condition */
pthread_cond_t wait_boite;
/* boite aux lettres mutex */
pthread_t boite_mutex;


/*
 * SYNCHRONIZATION ELEMENTS: collect area
 *
 */
/* collect area thread */
pthread_t collect_area_thread;
/* collect area condition */
pthread_cond_t waiting_for_cont;
pthread_cond_t collect_area_wait;
/* collect area mutex */
pthread_mutex_t collect_area_mutex;
pthread_mutex_t waiting_for_cont_mutex;


/*
 * SYNCHRONIZATION ELEMENTS: display
 *
 */
/* display thread */
pthread_t display_thread;

#endif //UTILS_H

