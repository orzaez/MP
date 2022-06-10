/*------------------------------------------------------------------*/
/* NOMBRE Y APELLIDOS:                                              */
/* DNI:                                                             */
/*------------------------------------------------------------------*/

#ifndef EXAMEN
#define EXAMEN

#include "funciones.h"
/*------------------------------------------------------------------*/
//HAZ AQUI LOS INCLUDE QUE CONSIDERES NECESARIOS
/*------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*------------------------------------------------------------------*/
//ESCRIBE AQUI LOS PROTOTIPOS DE TUS FUNCIONES
/*------------------------------------------------------------------*/
struct alumno* apartado1(int* nEle, char* nombreFichAlumnos, char* nombreFichNotas);
void apartado2(int nEle, struct alumno* Vector, char* nombreFichResultado);
struct alumno * reservaMemoria(int nEle);
int contarRegistros(char * nombreFichNotas);
void fichero_a_vector (char * nombreFichAlumnos, char * nombreFichNotas, struct alumno * v);
void vector_a_fichero(char* nombreFichResultado,struct alumno * Vector, int nEle);



#endif
