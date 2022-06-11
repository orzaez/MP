#include "funciones.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    La función debe volcar los datos del vector V1 y V2 en una cola (LS)
    teniendo en cuenta que no haya elementos repetidos (considerar repetidos
    si tienen la misma matricula).

    Deberás primero volcar los datos de V1 y luego V2. El tamaño de cada vector
    será tam1 y tam2 respectivamente.
*/

int ejercicio(struct coche * V1, struct coche * V2, int tam1, int tam2, struct lista ** LS){
    //COMPLETA
    int tamunido;
    struct coche * unido = reservaMemoria(tam1+tam2);
    unirVectores(V1,V2,tam1,tam2,unido,&tamunido);
    //NO OLVIDES CAMBIAR EL RETURN
    return tamunido;
}

//COMPLETA AQUÍ CON LAS FUNCIONES QUE HAYAS UTILIZADO
struct coche * reservaMemoria(int tam){
    struct coche * v = NULL;
    v = (struct coche *)malloc(sizeof(struct coche)*tam);
    if (v == NULL){
        printf("Error al reservar memoria");
        exit(-1);
    }
    return v;
}
void unirVectores(struct coche * v1, struct coche * v2, int tam1, int tam2, struct coche * unido, int * tamunido){
    (*tamunido) =0;
    for (size_t i = 0; i<tam1; i++){
        unido [i] = v1[i];
        (*tamunido)++;
    }
    int j = tam1;
    for (size_t i = 0; i<tam2; i++){
        int encontrado = buscarCoche(unido,tam1,v2[i].matricula);
        if (encontrado==0){
            unido[j]=v2[i];
            j++;
            (*tamunido)++;
        }
    }
}
int buscarCoche(struct coche * unido, int  tam, int matricula){
    for (int i = 0; i<tam; i++){
        if (unido[i].matricula==matricula){
            return 1;
        }
    }
    return 0;
}
