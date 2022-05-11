#include "fichero.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarActores(char * nF, struct actor a){
    FILE * fich = fopen(nF, "rb");
    if (fich == NULL){
        printf("Errror");
        exit(-1);
    }
    fseek (fich, 0, SEEK_END);
    double nbyte=ftell(fich);
    int tam = nbyte / sizeof(struct actor );
    fclose(fich);
    return(tam);
}