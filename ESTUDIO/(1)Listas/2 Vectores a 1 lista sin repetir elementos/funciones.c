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
	vector_a_lista(nEle1,nEle2,A1,A2,LS);
  int cont =0;
  cont=contarElementos(*LS);
  return cont;
  //RECUERDA HACER EL RETURN

}
//ESCRIBE AQU� TODAS LAS FUNCIONES QUE CONSIDERES NECESARIAS
void vector_a_lista(int nEle1, int nEle2, struct datos* A1, struct datos* A2, struct lista ** LS){
  for (int i =0; i<nEle1; i++){
    //insertarDelante(LP,C1[i]);
    if (A[i].nota>=9){
    insertarDelante(LS,A1[i]);

    }

  }
  for (int i =0; i<nEle1; i++){
    int encontrado = buscarLista(*LS, A2[i].codigo);
    if (A[i].nota>=9){
        if (encontrado == 0){
            insertarDelante(LS,A2[i]);
        }
    }
  }
}
struct lista * nuevoElemento(){
    struct lista * nuevo = NULL;
    nuevo = (struct lista*)malloc(sizeof(struct lista));
    if (nuevo == NULL){
        printf("Eerro");
        exit (-1);
    }
    return nuevo;
}
int buscarLista(struct lista *LS, int codigo){
    struct lista * aux = LS;
    while(aux!=NULL){
        if (aux -> codigo == codigo){
            return 1;
        }
        aux= aux-> sig;
    }
    return 0;
}
void insertarDelante(struct lista ** LS, struct datos  v){
    struct lista * nuevo = nuevoElemento();
    nuevo -> codigo = v.codigo;
    strcpy(nuevo->nombre, v.nombre);
    if ((*LS)==NULL){
        nuevo->sig=NULL;
    }else{
        nuevo->sig=(*LS);
    }
    (*LS)=nuevo;
}
int contarElementos(struct lista * LS){
    int cont =0;
    struct lista * aux = LS;
    while(aux!=NULL){
        cont++;
        aux=aux->sig;
    }
    return cont;
}