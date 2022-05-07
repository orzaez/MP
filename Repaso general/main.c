#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
int main (){
    int *v = NULL; //puntero a entero que contiene una pos de memoria
    int tam; //tamaño de la reserva de memoria
    scanf("%d", &tam);
    
    v=reservaMemoria(tam);
    mostrarVector(v, tam);
    liberaMemoria(&v);

    return 0;
}
///// PARA COMPILAR---> gcc main.c funciones.c -o repaso.out