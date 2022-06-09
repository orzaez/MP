/*
    www.academiamain.es
    605 45 70 99 (Ángel)
*/
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    La función ejercicio retorna un puntero a un array de elementos de tipo struct dato, el cual debe contener 
    los elementos de los arrays v1 y v2 pero ordenados por nombre alfabéticamente. 

    Además debe retornar por referencia el tamaño del vector que retorna por valor.

    Es decir, si por ejemplo se recibe un vector v1 de tamaño 5 y un vector v2 de tamaño 3, la función debe guardar 
    en el cuarto argumento (int * tam) un 8, y retornará mediante un return un vector con los 8 elementos ordenados 
    por nombre.
*/

struct dato * ejercicio(struct dato * v1,struct dato * v2,int tam1, int tam2, int * tam)
{
    //COMPLETA CAMBIANDO EL RETURN
    (*tam) = tam1 + tam2;
    struct dato * result = reservaMemoria(tam1+tam2);
    unirVectores(v1,v2,tam1,tam2,result);
    ordenarVector(result,tam1+tam2);
    return result;
}

//SUPONGO QUE TENDRE QUE SERVAR MEMORIA PORQUE VOY A GUARDAR DATOS EN OTRO VECTOR
struct dato * reservaMemoria(int tam){
    struct dato * v = NULL;
    v = (struct dato *)malloc(sizeof(struct dato)*tam);
    if (v == NULL){
        printf("Error al reservar memoria\n");
        exit(-1);
    }
    return v;
}
//COMO TENGO QUE UNIR DOS VECTORES, HAGO LA FUNCION QUE LOS UNA
void unirVectores(struct dato * v1, struct dato * v2, int tam1, int tam2,struct dato * resultado){
    for (size_t i = 0; i<tam1; i++){
        resultado [i] = v1[i];
    }
    for (size_t i = 0; i<tam2; i++){
        resultado [tam1+i] = v2[i];
    }

}
void ordenarVector(struct dato * v, int tam){
    for (size_t i = 0; i < tam; i++)
    {
        for (size_t j = i+1; j < tam; j++)
        {
            if(strcmp(v[i].nombre,v[j].nombre)>0)
            {
                struct dato aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
        
    }
}