/*
    www.academiamain.es
    605 45 70 99 (Ángel)
*/
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
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
    int tam = contarElementos(*aprobados);
    tam += contarElementos(*suspensos);
    printf("%d",tam);
    //NO OLVIDES CAMBIAR EL RETURN
    return tam;
}

//COMPLETA AQUÍ CON LAS FUNCIONES QUE NECESITES

//PRIMERO SE DEBE DE PASAR EL FICHERO A UNA LISTA 

void fichero_a_lista(char * fichero, struct lista ** aprobados, struct lista ** suspensos){
    FILE * fich = fopen(fichero, "r");
    if ( fich == NULL ){
        printf("Error al abrir fichero");
        exit(-1);        
    }
    struct alumno a;
    while(fgets(a.nombre,LENGTH,fich)){
        //a.nombre[strlen(a.nombre)-1] = '\0';
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
    struct lista * nuevo= NULL;
    nuevo = (struct lista *)malloc(sizeof(struct lista));
    if ( nuevo == NULL ){
        exit (-1);
    }
}

void insertarDetras(struct lista ** LS, struct alumno a){
    struct lista * nuevo = nuevoElemento();
    nuevo->dato=a;
    nuevo -> siguiente = NULL;
    if ((*LS)==NULL){
        (*LS)=nuevo;
    }else{
        struct lista * aux = (*LS);
        while(aux->siguiente!=NULL){
            aux=aux->siguiente;
        }
        aux->siguiente= nuevo;
    }
}

int contarElementos(struct lista * LS){
    int cont = 0;
    struct lista * aux = LS;
    while (aux!=NULL){
        cont++;
        aux=aux->siguiente;
    }
    return cont;
}

