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

int ejercicio(struct coche * V1, struct coche * V2, int tam1, int tam2, struct lista ** LS)
{
    //COMPLETA
    vector_a_lista(V1,V2,tam1,tam2,LS);
    int tam = contarElementos(*LS);//NO OLVIDES CAMBIAR EL RETURN
    return tam;
}

//COMPLETA AQUÍ CON LAS FUNCIONES QUE HAYAS UTILIZADO


void vector_a_lista(struct coche *V1,struct coche * V2,int tam1,int tam2, struct lista** LS){
   for (int i =0; i<tam1;i++){
       insertarDetras(LS, V1[i]);
   }
   for (int i =0; i<tam1;i++){
       int encontrado = buscarElemento(*LS, V2[i].matricula);
       if (encontrado==0){
        insertarDetras(LS, V2[i]);
           
       }
   }
}

void insertarDetras(struct lista**LS, struct coche dato){
    struct lista* nuevo= nuevoElemento();
    nuevo->matricula=dato.matricula;
    strcpy(nuevo->marca,dato.marca);
    nuevo->anio_matriculacion=dato.anio_matriculacion;
    nuevo->siguiente=NULL;

    if((*LS)==NULL)
    {
       (*LS)=nuevo;
    }

    else
    {
        struct lista* aux=(*LS);
        while(aux->siguiente!=NULL)
        {
            aux=aux->siguiente;
        }
        aux->siguiente=nuevo;
    }
    
}

struct lista * nuevoElemento(){
    struct lista *nuevo= NULL;
    nuevo=(struct lista*)malloc(sizeof(struct lista));
    if(nuevo==NULL)
    {
        printf("Error en la reserva de memoria\n");
        exit(-1);
    }
    return nuevo;
}

int contarElementos(struct lista *LS){
    struct lista * aux = LS;
    int cont=0;
    while ( aux!= NULL)
    {
        cont++;
        aux= aux->siguiente;
    }
    return cont;
}


int buscarElemento(struct lista*LS, int matricula){
    struct lista * aux = LS;
    while ( aux!= NULL)
    {
        if(aux->matricula==matricula)
        {
            return 1;
        }
        else
        {
            aux=aux->siguiente;
        }
    } return 0;
}