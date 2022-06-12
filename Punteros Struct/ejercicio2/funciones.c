#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct objeto * reservar_memoria (int tam){
    struct objeto * o = NULL;
    o = (struct objeto*) malloc (sizeof (struct objeto)* tam);
    if ( o == NULL) {
        printf("ERROR AL RESERVAR MEMORIA");
        exit (-1);
    } 
    return o;
}

void rellenarVector (struct objeto *o, int tam){
    for (int i =0; i<tam; i++){
        printf("Introduzca el codigo del objeto: ");
        getchar();
        fgets (o[i].codigo, 10, stdin);

        printf("Introduzca el tipo del objeto: ");
        scanf ("%i",&o[i].tipo);

        printf("Introduzca el peso del objeto: ");
        scanf ("%f",&o[i].peso);
    }
}

void comparapeso(struct objeto *o, int tam){
    for (int i=0; i<tam; i++){
        int j =0;
        if (o[i].peso>o[i+1].peso){
            printf("El objeto con peso %f es el mas pesado \n",o[i].peso );
        }
        if (o[j].peso<o[i+1].peso){
            printf("El objeto con peso %f es el menos pesado \n",o[i].peso );
        }
    }
}



void liberaMemoria (struct objeto **o){
     free(*o);
    (*o)=NULL;
}
