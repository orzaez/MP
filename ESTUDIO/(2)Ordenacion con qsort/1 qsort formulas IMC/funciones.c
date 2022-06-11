/*------------------------------------------------------------------*/
/* NOMBRE Y APELLIDOS:                                              */
/* DNI:                                                             */
/*------------------------------------------------------------------*/

#include "funciones.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//HAZ AQUI LOS INCLUDE QUE SEAN NECESARIOS


/*------------------------------------------------------------------*/
/*Ejercicio 1: Ordenacion y punteros a funciones
               nEle: n�mero de elementos del vector
               Vector: el vector a ordenar
               criterio: 0-->ascendente por indice de masa corporal
                         1-->descendente por nombre 
/*------------------------------------------------------------------*/
void ejercicio1(int nEle, struct datos* Vector, int criterio)
{

     if(criterio==0) 
     {
         //INCLUYE AQUI LA LLAMADA A TU FUNCI�N DE ORDENACI�N PARA ORDEN ASCENDENTE
        qsort((struct datos*)Vector,nEle,sizeof(struct datos) ,&imcAsc);         
     }
     else 
     {
         //INCLUYE AQUI LA LLAMADA A TU FUNCI�N DE ORDENACI�N PARA ORDEN DESCENDENTE
        qsort((struct datos *)Vector, nEle, sizeof(struct datos),&nombreDes);
     }
}

//ESCRIBE AQU� TU FUNCION DE ORDENACI�N Y TODAS LAS FUNCIONES QUE CONSIDERES NECESARIAS
int imcAsc (const void * e1, const void * e2){
    struct datos * a;
    struct datos * b;
    a = (struct datos*)e1;
    b = (struct datos*)e2;
    float imcA=a->pesoKg/(a->alturaM*a->alturaM);
    float imcB=b->pesoKg/(b->alturaM*b->alturaM);
    if (imcA > imcB){
        return 1;
    }
    return 0;
}

int nombreDes(const void * e1,const void * e2){
    struct datos * a;
    struct datos * b;
    a = (struct datos *)e1;
    b = (struct datos *)e2;
    if (strcmp(a->nombre,b->nombre)<0){
        return 1;
    }
    return 0;

}