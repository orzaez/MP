#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **agrv ){
    if (argc !=2){
        printf (" Error linea argumento. \n");
        exit(-1);
    }
    int tam = atoi(agrv[1]);
    struct alumno *v= NULL;
    float cad;
    char dni;
    
    v = reservar_memoria(tam);
    rellenarVector(v,tam);
    buscarAlumno(v,tam,&dni);
    liberaMemoria(&v);
    return 0;
}