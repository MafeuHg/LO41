#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#ifndef UTILS_H
#define UTILS_H

/* concern utilities of the program */
typedef int BOOL;
#define TRUE 0
#define FALSE 1

/* Concerns operators */
#define MAX_LENGTH_NAME 127
#define MAX_LENGTH_PRODUCT_NAME 20

/* Concerns the main program */
#define NB_OPERATORS 7 // the number of operators
#define NB_MUTEX 8

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
pthread_cond_t waitFiber;
pthread_cond_t waitPlastic;
pthread_cond_t fiberStock;
pthread_cond_t plasticStock;

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

unsigned long int production_operator_1 = 0;
unsigned long int production_operator_2 = 0;
unsigned long int production_operator_3 = 0;
unsigned long int production_operator_4 = 0;
//unsigned long int production_operator_5_1 = 0;
//unsigned long int production_operator_5_2 = 0;
unsigned long int production_operator_5_final = 0;
//unsigned long int production_operator_6_1 = 0;
//unsigned long int production_operator_6_2 = 0;
unsigned long int production_operator_6_final = 0;
//unsigned long int production_operator_7_1 = 0;
//unsigned long int production_operator_7_2 = 0;
unsigned long int production_operator_7_final = 0;

pthread_t operators[NB_OPERATORS];


#endif //UTILS_H

