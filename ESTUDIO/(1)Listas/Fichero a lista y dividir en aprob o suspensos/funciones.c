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
*/

int ejercicio(char * fichero, struct lista ** aprobados, struct lista ** suspensos)
{
    fichero_a_listas(fichero,aprobados,suspensos);
    int tam = contarElementos(*aprobados);
    tam += contarElementos(*suspensos);

    //NO OLVIDES CAMBIAR EL RETURN
    return tam;
}

//COMPLETA AQUÍ CON LAS FUNCIONES QUE NECESITES

//PRIMERO SE DEBE DE PASAR EL FICHERO A UNA LISTA 
void fichero_a_listas(char * fichero, struct lista ** aprobados, struct lista ** suspensos){
    FILE * f = fopen (fichero, "r");//Abro el fichero
    if(f==NULL){
        printf("Error al abrir el fichero\n");
    }
    struct alumno a;
    while(fgets(a.nombre,LENGTH,f))
    {
        a.nombre[strlen(a.nombre)-1] = '\0';
        fscanf(f,"%d %f\n",&a.curso,&a.nota);
        if(a.nota>=5)
        {
            encolar(aprobados,a);
        }
        else
        {
            encolar(suspensos,a);
        }
    }
    fclose(f);
}

int contarElementos (struct lista * alumnos){//OK
    int cont = 0;
    struct lista * aux = alumnos;
    while (aux != NULL){
        cont++;
        aux = aux -> siguiente;
    }
    return cont;
}
struct lista * nuevoElemento(){
    struct lista * nuevo = NULL;
    nuevo = (struct lista *)malloc(sizeof(struct lista));
    if (nuevo == NULL){

    printf("Error al reservar memoria");
        exit(-1);
    }
    return nuevo;
}

void encolar (struct lista ** alumnos, struct alumno a){//SIEMPRE QUE ENCOLAR O COLAR NUEVO ELEMENTO
    struct lista * nuevo = nuevoElemento();
    nuevo -> dato= a;
    nuevo -> siguiente = NULL;
    if ((*alumnos)==NULL){
        (*alumnos)=nuevo;
    }else{
        struct lista * aux = (*alumnos);
        while (aux -> siguiente!= NULL){
            aux = aux -> siguiente;
        }
        aux -> siguiente = nuevo;
    }

}
