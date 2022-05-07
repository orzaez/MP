#include "fichero.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 int main(char argc, char ** argv){

    if (argc=!2){
        printf("Error");
        exit(-1);
    }
    char * nF = argv[1];
    struct actor * a;
    int tam = contarActores(nF,*a);
    a = reservaMemoria (tam);
    printf("En este registro hay %i actores", contarActores(nF,*a));
    fichero_a_vector(nF,tam);
    vector_a_fichero(nF,*a,tam);
    liberarMemoria(&a);

    return 0;
 }