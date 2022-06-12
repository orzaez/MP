#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void insertarDelante(struct nodo **cabeza, int dato){
    struct nodo * nuevo = nuevoElemento();
    nuevo -> dato = dato;//EL DATO LO GUARDO EN PELOTA FLECHA NUEVA (*nuevo).dato
    if ((*cabeza)==NULL){//La lista esta vacia???
        nuevo -> sig = NULL;
    }else{
        nuevo-> sig=(*cabeza); 
    }
    (*cabeza)=nuevo;//aqui estoy poniendo el dato el primero, APILO
}
struct nodo * nuevoElemento(){//como reservar memoria en punteros
    struct nodo * nuevo = NULL;
    nuevo = (struct nodo *)malloc(sizeof(struct nodo));//reservo memoria para ese struct * nodo SOLO PARA 1
    if (nuevo==NULL){
        printf("Error al reservar memoria");
        exit(-1);
    }
    return nuevo;
}void mostrarLista(struct nodo * cabeza){
    struct nodo * aux = cabeza;
    while (aux != NULL){
        printf ("%d\n", aux -> dato);
        aux = aux -> sig;
    }
}
int contarLista(struct nodo * cabeza){
    int cont=0;
    struct nodo * aux = cabeza;
    while (aux != NULL){
        cont++;
        aux = aux -> sig;
    }
    return cont;
}
void insertarDetras(struct nodo ** cabeza, int dato){
    struct nodo * nuevo = nuevoElemento();
    nuevo -> dato = dato;
    nuevo -> sig = NULL;
    if ((*cabeza)==NULL){
        (*cabeza)=nuevo;
    }else{
        struct nodo * aux = (*cabeza);
        while(aux -> sig != NULL){//solo sera aux->sig aqui lo demas aux!=NULL
            aux = aux -> sig;
        }
        aux -> sig = nuevo;
    }

}
void borrarLista(struct nodo ** cabeza){
    struct nodo * aux;
    while ((*cabeza)!=NULL){
        aux = (*cabeza);
        (*cabeza) = (*cabeza)->sig;
        free (aux);
    }

}
void borrarNodo(struct nodo ** cabeza, int dato){
    struct nodo * anterior;
    struct nodo * aux = (*cabeza);
    while (aux != NULL && aux -> dato!=dato){
        anterior = aux;
        aux = aux -> sig;
    }
    if (aux != NULL){
        if (aux == (*cabeza)){
            (*cabeza)=(*cabeza)->sig;//Borro la cabeza
        }else{
            anterior -> sig = aux -> sig;//borro nodo del medio o ultimo
        }
        free(aux);
    }

}