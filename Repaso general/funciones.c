#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
int * reservaMemoria(int tam){
    int * v = NULL;
    v = (int *)malloc(sizeof(int)*tam);
    if (v==NULL){//control de errores IMPORTANTE!!!!!!!!
        printf("Error reserva memoria.h");
        exit (-1);
    }
    return v;
}
void mostrarVector(int *v, int tam){
    for(int i = 0; i < tam; i++){
        printf ("%d\n", v[i]);
    }
}

void liberaMemoria(int **v){
    free(*v);
    (*v)=NULL;
}