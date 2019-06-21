/*
 * display.h
 * written by GUICHARD Mériadeg
 *
 * contains:
 *      the definition of a displayer
 *      the functions that display the production to the screen
 */

#ifndef DISPLAYER_H
#define DISPLAYER_H

typedef struct{

    char **product_names;

}displayer;

displayer *initialize_displayer(char **list);
void *display(void *d);

#endif //DISPLAYER_H

