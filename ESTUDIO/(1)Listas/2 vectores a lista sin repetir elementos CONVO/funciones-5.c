/*------------------------------------------------------------------*/
/* NOMBRE Y APELLIDOS:                                              */
/* DNI:                                                             */
/*------------------------------------------------------------------*/
#include "funciones.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//HAZ AQUI LOS INCLUDE QUE SEAN NECESARIOS


/*------------------------------------------------------------------*/
/*Ejercicio 3: Listas
  -nEle1, nEle2: El n�mero de elementos de los vectores C1 y C2 respectivamente
  -C1 y C2: Vectores con los alumnos presentados en primera y segunda convocatoria. Ya se han reservado y rellenado en el main.
  -LP: Lista de alumnos presentados a alguna de las convocatorias.
  -VALOR DEVUELTO: La funci�n devolver� el n�mero de alumnos de la lista LP.

/*------------------------------------------------------------------*/

int ejercicio3(int nEle1, int nEle2, struct datos* C1, struct datos* C2, struct lista ** LP)
{
  //INCLUYE AQUI EL CODIGO NECESARIO PARA RESOLVER EL EJERCICIO
  //RECUERDA HACER EL RETURN
  /*vector_a_lista(nEle1,nEle2,C1,C2,LP);
  int cont =0;
  cont=contarElementos(*LP);
  return cont;*/
 
  vector_a_lista(nEle1,nEle2,C1,C2,LP);
   int cont = 0;
  cont = contarElementos(*LP);
  return cont;

}
//ESCRIBE AQU� TU FUNCION RECURSIVA Y TODAS LAS FUNCIONES QUE CONSIDERES NECESARIAS
void vector_a_lista(int nEle1, int nEle2, struct datos * C1, struct datos * C2, struct lista ** LP){
  for (int i =0; i<nEle1; i++){
    insertarDelante(LP, C1[i]);
  }
  for (int i =0; i<nEle2; i++){
   int encontrado=buscarLista(*LP, C2[i].codigo);
   if (encontrado == 0){
      insertarDelante(LP,C2[i]);
    }

  }
}
struct lista * nuevoElemento(){
  struct lista * nuevo = NULL;
  nuevo = (struct lista *)malloc(sizeof(struct lista));
  if (nuevo == NULL){
    printf("Error");
    exit(-1);
  }
}
void insertarDelante(struct lista ** LP, struct datos v){
  struct lista * nuevo = nuevoElemento();
  nuevo->codigo=v.codigo;
  strcpy(nuevo->nombre, v.nombre);
  if ((*LP)==NULL){
    nuevo->sig=NULL;
  }else{
    nuevo->sig=(*LP);
  }
  (*LP)=nuevo;
}
int buscarLista(struct lista * LP, int codigo){
  struct lista * aux = LP;
  while(aux!=NULL){
    if (aux->codigo == codigo){
      return 1;
    }
    aux = aux->sig;
  }
  return 0;
}
int contarElementos(struct lista * LP){
  int cont =0;
  struct lista * aux = LP;
  while(aux != NULL){
    cont++;
    aux=aux->sig;
  }
  return cont;
}






/*
void vector_a_lista(int nEle1, int nEle2, struct datos* C1, struct datos* C2, struct lista ** LP){
  for (int i =0; i<nEle1; i++){
    //insertarDelante(LP,C1[i]);
    insertarDelante(LP,C1[i]);

  }
  for (int i =0; i<nEle2; i++){
    int encontrado = buscarLista(*LP,C2[i].codigo);
    if (encontrado == 0){
      insertarDelante(LP,C2[i]);
    }
  }
}
struct lista * nuevoElemento(){
  struct lista * nuevo = NULL;
  nuevo = (struct lista*)malloc(sizeof(struct lista));
  if (nuevo == NULL){
    printf("ERROR AL INTRODUCIR NUEVO ELEMENTO");
    exit(-1);
  }
  return nuevo;
}

int buscarLista(struct lista * LP, int codigo){
  struct lista *aux=LP;
  while(aux!=NULL){
    if (aux -> codigo == codigo){
      return 1;
    }
    aux=aux->sig;
  }
  return 0;
}
void insertarDelante(struct lista **LP, struct datos v){
  struct lista * nuevo = nuevoElemento();
  nuevo -> codigo=v.codigo;
  strcpy(nuevo->nombre,v.nombre);
  if((*LP)==NULL){
    nuevo->sig=NULL;
  }else{
    nuevo->sig=(*LP);
  }
  (*LP)=nuevo;
}
int contarElementos(struct lista *LP){
	int cont=0;
	struct lista *aux=LP;
	while(aux!=NULL){
		cont++;
		aux=aux->sig;
	}
	return cont;
}
*/