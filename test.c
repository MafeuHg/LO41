#include "libs.h"
#include "pieces.h"

int main(int argc, char** argv)
{
    piece *p = piece_initialisation(47, "Jacques Chirac");
    fprintf(stdout, "Ref: %d\nNom: %s\n", p->reference, p->name);

    return EXIT_SUCCESS;
}

