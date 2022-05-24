#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

struct nodo * nuevoElemento(){//ESTA FUNCION ES LA MISMA PARA TODOS LOS CASOS
    struct nodo * nuevo = NULL;
    nuevo = (struct nodo *)malloc(sizeof(struct nodo));//reservo memoria para ese struct * nodo SOLO PARA 1
    if (nuevo==NULL){
        printf("Error al reservar memoria");
        exit(-1);
    }
    return nuevo;
}
void insertarDelante(struct nodo **cabeza,struct alumno dato){
    struct nodo * nuevo = nuevoElemento();
    nuevo -> dato = dato;//EL DATO LO GUARDO EN PELOTA FLECHA NUEVA (*nuevo).dato
    if ((*cabeza)==NULL){//La lista esta vacia???
        nuevo -> sig = NULL;
    }else{
        nuevo-> sig=(*cabeza); 
    }
    (*cabeza)=nuevo;//aqui estoy poniendo el dato el primero, APILO
}
void insertarDetras(struct nodo **cabeza,struct alumno dato){
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
void mostrarLista(struct nodo * cabeza){
    struct nodo * aux = cabeza;
    while (aux != NULL){
        printf ("Nombre: %s", (aux -> dato).nombre);
        printf (" Edad: %d", (aux -> dato).edad);
        printf (" Nota: %f\n", (aux -> dato).nota);


        aux = aux -> sig;
    }
    
}
int contarElementos(struct nodo * cabeza){
    int cont=0;
    struct nodo * aux = cabeza;
    while (aux != NULL){
        cont++;
        aux = aux -> sig;
    }
    return cont;
}
int buscarAlumno(struct nodo *cabeza, char * nombre){
    struct nodo * aux = cabeza;
    while (aux != NULL){
        if (strcmp(nombre,(aux -> dato).nombre)){
            return 1;
        }
        aux = aux -> sig;
    }
    return -1;
}
void borrarLista(struct nodo **cabeza){
    struct nodo * aux;
    while ((*cabeza)!=NULL){
        aux = (*cabeza);
        (*cabeza) = (*cabeza)->sig;
        free (aux);
    }
}

