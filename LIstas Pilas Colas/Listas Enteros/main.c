#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main (){
    //crear lista cabesa
    struct nodo * cabeza =  NULL;
    insertarDelante(&cabeza,1);//apilar, paso por referencia porque voy a modificarla
    insertarDelante(&cabeza,2);//apilar 
    insertarDelante(&cabeza,3);//apilar 
    mostrarLista(cabeza);
    int tam = contarLista(cabeza);
    printf("La lista tiene %d",tam);
    insertarDetras(&cabeza,4);
    insertarDetras(&cabeza,7);


    
    borrarLista(&cabeza);



}