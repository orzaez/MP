#include "funciones.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    La función debe almacenar en LISTA1 todos los datos cuyo peso sean menores o iguales a PESO
    y en LISTA2 los restantes. La primera es una pila y la segunda una cola.
    
    Además la función debe retornar el número de elementos que se han volcado a la lista.
*/

void apartado1(int * tam1, int * tam2, struct dato * VECTOR, int NUMELEMENTOS, struct lista ** LISTA1,  struct lista ** LISTA2, float PESO)
{
    
    vector_a_lista(tam1,tam2,VECTOR,NUMELEMENTOS,LISTA1,LISTA2,PESO);
    int cont = contarElementos(*LISTA2);
    //NO OLVIDES CAMBIAR EL RETURN
    printf ("%d\n",cont);
}

/*
    Funcion que calcula el número de elementos de una lista usando recursividad.
*/


void vector_a_lista(int * tam1, int * tam2, struct dato * VECTOR, int NUMELEMENTOS, struct lista ** LISTA1,  struct lista ** LISTA2, float PESO){
    (*tam1)=0;
    (*tam2)=0;
    for (int i=0;i<NUMELEMENTOS;i++){
        if (VECTOR[i].peso<=PESO){
            insertarDelante(LISTA1,VECTOR[i]);
            (*tam1)++;
        }else{
            insertarDetras(LISTA2,VECTOR[i]);
            (*tam2)++;
            
        }
    }
}
struct lista * nuevoElemento(){
    struct lista * nuevo = NULL;
    nuevo = (struct lista *)malloc(sizeof(struct lista));
    if ( nuevo == NULL ){
        printf("Error");
        exit(-1);
    }
}

void insertarDetras(struct lista ** LISTA2, struct dato v){
    struct lista * nuevo = nuevoElemento();
    nuevo->elemento=v;
    nuevo->siguiente=NULL;
    if ((*LISTA2)==NULL){
        (*LISTA2)=nuevo;
    }else{
        struct lista * aux = (*LISTA2);
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente=nuevo;
    }
}

void insertarDelante(struct lista ** LISTA1, struct dato v){
    struct lista * nuevo = nuevoElemento();
    nuevo->elemento=v;
    if ((*LISTA1)==NULL){
        nuevo->siguiente=NULL;
    }else{
        nuevo->siguiente=(*LISTA1);
    }
    (*LISTA1)=nuevo;
}

int contarElementos(struct lista * LISTA1){
    int cont=0;
    struct lista * aux = (LISTA1);
    while(aux!=NULL){
        cont++;
        aux=aux->siguiente;
    }
    return cont;
}
















/*struct lista * nuevoElemento(){//ESTA FUNCION ES LA MISMA PARA TODOS LOS CASOS
    struct lista * nuevo = NULL;
    nuevo = (struct lista *)malloc(sizeof(struct lista));//reservo memoria para ese struct * nodo SOLO PARA 1
    if (nuevo==NULL){
        printf("Error al reservar memoria");
        exit(-1);
    }
    return nuevo;
}
void insertarDelante(struct lista **LISTA1,struct dato VECTOR){
    struct lista * nuevo = nuevoElemento();
    nuevo -> elemento = VECTOR;//EL DATO LO GUARDO EN PELOTA FLECHA NUEVA (*nuevo).dato
    if ((*LISTA1)==NULL){//La lista esta vacia???
        nuevo -> siguiente = NULL;
    }else{
        nuevo-> siguiente=(*LISTA1); 
    }
    (*LISTA1)=nuevo;//aqui estoy poniendo el dato el primero, APILO
}
void insertarDetras(struct lista **LISTA2,struct dato VECTOR){
    struct lista * nuevo = nuevoElemento();
    nuevo -> elemento = VECTOR;//EL DATO LO GUARDO EN PELOTA FLECHA NUEVA (*nuevo).dato
    nuevo -> siguiente = NULL;
    if ((*LISTA2)==NULL){
        (*LISTA2)=nuevo;
    }else{
        struct lista * aux = (*LISTA2);
        while(aux -> siguiente != NULL){//solo sera aux->sig aqui lo demas aux!=NULL
            aux = aux -> siguiente;
        }
        aux -> siguiente = nuevo;
    }

}
void vector_a_lista(struct lista **LISTA1,struct lista **LISTA2,struct dato *VECTOR,int NUMELEMENTOS,float limite,int * tam1, int *tam2){
    (*tam1)=0;
    (*tam2)=0;
    for(int i=0;i<NUMELEMENTOS;i++){
        if(VECTOR[i].peso<=limite){
            insertarDelante(LISTA1,VECTOR[i]);
            (*tam1)++;
        }
        else
        {
            insertarDetras(LISTA2,VECTOR[i]);
            (*tam2)++;
        }
    }
}*/



void apartado2(int * tam, struct lista * LISTA)
{

}

//COMPLETA
/*contarElementos(struct lista * LISTA){
    struct lista * aux = LISTA;
    int cont = 0;
    while(aux!=NULL){
        cont++;
        aux->sig=LISTA;
    }
    return cont;
}*/