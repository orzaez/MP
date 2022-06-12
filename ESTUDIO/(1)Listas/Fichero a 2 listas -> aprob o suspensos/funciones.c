/*
    www.academiamain.es
    605 45 70 99 (Ángel)
*/
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
fichero_a_lista(fichero,aprobados,suspensos);
    int tam = contarElementos(*aprobados);
    tam += contarElementos(*suspensos);
    printf("%d",tam);
    //NO OLVIDES CAMBIAR EL RETURN
    return tam;

    La función ejercicio recibe el nombre de un fichero de alumnos como primer argumento,
    como segundo argumento una lista llamada aprobados, y como tercer argumento, una lista llamada
    suspensos. 
 
    La función debe encolar en la lista aprobados los alumnos del fichero que estén aprobados,
    y en la cola suspensos, aquellos que estén suspensos.

    Además deberá retornar el número de alumnos total procesados en el fichero.



    fichero_a_listas(fichero,aprobados,suspensos);
    int tam = contarElementos(*aprobados);
    tam += contarElementos(*suspensos);
*/

int ejercicio(char * fichero, struct lista ** aprobados, struct lista ** suspensos)
{
    fichero_a_lista(fichero,aprobados,suspensos);
    int cont= contarElementos(*aprobados);
    cont += contarElementos(*suspensos);
   printf("%d", cont);

    return cont;
}

//COMPLETA AQUÍ CON LAS FUNCIONES QUE NECESITES

//PRIMERO SE DEBE DE PASAR EL FICHERO A UNA LISTA
void fichero_a_lista(char * fichero, struct lista ** aprobados, struct lista ** suspensos){
    FILE * fich = fopen ( fichero, "r");
    if ( fichero == NULL){
        exit(-1);
    }
    struct alumno a;
    while(fgets(a.nombre,LENGTH,fich)){
        a.nombre[strlen(a.nombre)-1]='\0';
        fscanf(fich,"%d %f\n", &a.curso,&a.nota);
        if (a.nota>=5){
            insertarDetras(aprobados,a);
        }else{
            insertarDetras(suspensos,a);
        }
    }
    fclose(fich);
} 

struct lista * nuevoElemento(){
    struct lista * nuevo = NULL;
    nuevo = (struct lista *)malloc(sizeof(struct lista));
    if ( nuevo == NULL ){
        printf("Error");
        exit(-1);
    }
}
void insertarDetras(struct lista ** LISTA, struct alumno a){
    struct lista * nuevo = nuevoElemento();
    nuevo->dato=a;
    nuevo->siguiente= NULL;
    if ((*LISTA)==NULL){
        (*LISTA)=nuevo;
    }else{
        struct lista * aux = (*LISTA);
        while (aux->siguiente!=NULL){
            aux=aux->siguiente;
        }
        aux->siguiente=nuevo;
    }
}

int contarElementos(struct lista * LISTA){
    int cont =0;
    struct lista * aux = LISTA;
    while(aux!=NULL){
        cont++;
        aux=aux->siguiente;
    }
    return cont;
}
