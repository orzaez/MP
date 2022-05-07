#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char **argv){
    if (argc =!2){
        printf("ERRRRRORRR");
        exit (-1);
    }
    int tam = atoi(argv[1]);
    struct objeto *o = NULL;


    o = reservar_memoria(tam);
    rellenarVector(o,tam);
    comparapeso(o,tam);
    liberaMemoria(&o);
    
    return 0;
}