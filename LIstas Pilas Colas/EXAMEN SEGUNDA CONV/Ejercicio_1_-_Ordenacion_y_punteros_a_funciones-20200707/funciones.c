/*------------------------------------------------------------------*/
/* NOMBRE Y APELLIDOS:                                              */
/* DNI:                                                             */
/*------------------------------------------------------------------*/

#include "funciones.h"

//HAZ AQUI LOS INCLUDE QUE SEAN NECESARIOS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



/*------------------------------------------------------------------*/
/*Ejercicio 1: Ordenacion y punteros a funciones
               nEle: n�mero de elementos del vector
               Vector: el vector a ordenar. Ya ha sido reservado 
                       y se ha rellenado en el main
               criterio: 0-->ascendente por salario NETO
                         1-->descendente por nombre 
/*------------------------------------------------------------------*/
void ejercicio1(int nEle, struct nomina* Vector, int criterio)
{

     if(criterio==0) 
     {
         //INCLUYE AQUI LA LLAMADA A TU FUNCI�N DE ORDENACI�N PARA ORDEN ASCENDENTE
         qsort ((struct nomina *)Vector, nEle,sizeof(struct nomina), &nominaAsc);

     }
     else 
     {
         //INCLUYE AQUI LA LLAMADA A TU FUNCI�N DE ORDENACI�N PARA ORDEN DESCENDENTE
         qsort ((struct nomina *)Vector, nEle,sizeof(struct nomina), &nombreDesc);

     }
}

//ESCRIBE AQU� TU FUNCION DE ORDENACI�N Y TODAS LAS FUNCIONES QUE CONSIDERES NECESARIAS
int nominaAsc(const void *e1, const void * e2){
    struct nomina * a;
    struct nomina * b;
    a = (struct nomina *)e1;
    b = (struct nomina *)e2;
    /*int * salario_neto_a = a->salarioBruto - a->salarioBruto*(retenciones/100);
    int * salario_neto_b = a->salarioBruto - a->salarioBruto*(retenciones/100); */
    if ((a->salarioBruto - a->salarioBruto*(a->retenciones/100)) > b->salarioBruto - b->salarioBruto*(b->retenciones/100)){
        return 1;
    }
    return 0;

}
int nombreDesc(const void *e1, const void *e2){
    struct nomina * a;
    struct nomina * b;
    a = (struct nomina *)e1;
    b = (struct nomina *)e2;
    if (strcmp(a->nombre,b->nombre)<0){
        return 1;
    }
    return 0;

}