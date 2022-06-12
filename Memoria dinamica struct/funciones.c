#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

struct persona * reservaMemoria (int tam){
    struct persona * v = NULL;
    v = (struct persona*) malloc (sizeof (struct persona)* tam);//reserva de memoria de tipo struct
    if ( v == NULL){
        printf ("Error al reservar memoria.\n");
        exit (-1);
    }
    return v;
}

void rellenarVector (struct persona *v, int tam){//RELLENAMOS VECTOR
    for (int i =0; i<tam; i++){
        printf ("Introduce el nombre: ");
        getchar();
        fgets (v[i].nombre, 100, stdin);//Se traga los espacios hasta el intro, stdin es entrada estandar que es teclado.

        printf ("Introduce el apellido: ");
        scanf ("%s", v[i].apellido);//con el %s introduzco una cadena de caracteres

        printf ("Introduce la edad: ");
        scanf ("%d", &v[i].edad);//con el %d introduzco una cadena de caracteres, 
        //el scanf pongo & porque no es un puntero, sin embargo el apellido si que lo hemos declarado como 

    }
}

void mediaEdad(struct persona * v, int tam , float * media ){
    float suma = 0;
    for ( int i =0; i<tam; i++){
        suma = suma + v[i].edad;
    }
    (*media)=suma/tam;
}

void liberaMemoria(struct persona **v){
    free(*v);
    (*v)=NULL;
}