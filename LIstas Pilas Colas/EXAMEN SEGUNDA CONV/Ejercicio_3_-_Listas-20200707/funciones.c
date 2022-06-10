/*------------------------------------------------------------------*/
/* NOMBRE Y APELLIDOS:                                              */
/* DNI:                                                             */
/*------------------------------------------------------------------*/
#include "funciones.h"

//HAZ AQUI LOS INCLUDE QUE SEAN NECESARIOS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*------------------------------------------------------------------*/
/*Ejercicio 3: Listas
	-nEle1, nEle2: El n�mero de elementos de los vectores A1 y A2 respectivamente
	-A1 y A2: Vectores con los alumnos y las notas en dos asignaturas. Ya se han reservado y rellenado en el main.
	-LS: Lista de alumnos cuya nota en las dos asignaturas es de sobresaliente.
	VALOR DEVUELTO: La funci�n devolver� el n�mero de alumnos de la lista LS.


/*------------------------------------------------------------------*/

int ejercicio3(int nEle1, int nEle2, struct datos* A1, struct datos* A2, struct lista ** LS)
{
  //INCLUYE AQUI EL CODIGO NECESARIO PARA RESOLVER EL EJERCICIO
	
  //RECUERDA HACER EL RETURN

}

//ESCRIBE AQU� TODAS LAS FUNCIONES QUE CONSIDERES NECESARIAS
void vector_a_lista(int nEle1, int nEle2, struct datos* A1, struct datos* A2, struct lista ** LS){
    for(int i=0;i<NUMELEMENTOS;i++){
        if(A1.nota>=9){
            insertarDelante(LS,vector[i]);
        }
    }
	for(int i=0;i<NUMELEMENTOS;i++){
        if(A2.nota>=9){
            insertarDelante(LS,vector[i]);
        }
    }
}
void insertarDelante(struct lista **LS,struct dato VECTOR){
    struct lista *nuevo=nuevoElemento();
    nuevo->codigo=VECTOR;
    if((*LS)==NULL){
        nuevo->sig=NULL;
    }else{
        nuevo->sig=(*LS);
    }
    (*LS)=nuevo;
}
struct lista * nuevoElemento(){//ESTA FUNCION ES LA MISMA PARA TODOS LOS CASOS
    struct lista * nuevo = NULL;
    nuevo = (struct lista *)malloc(sizeof(struct lista));//reservo memoria para ese struct * nodo SOLO PARA 1
    if (nuevo==NULL){
        printf("Error al reservar memoria");
        exit(-1);
    }
    return nuevo;
}