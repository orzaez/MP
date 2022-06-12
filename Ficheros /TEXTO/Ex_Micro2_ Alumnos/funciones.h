#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  struct alumno {
    char nombre [1000];
    long dni;
    float media;
};
//void bin_a_txt(char * nF, struct producto * p, long tam);
int contarRegistros(char * nF);
struct alumno * reservaMemoria(int tam);
void liberarMemoria(struct alumno **v);
void fichero_a_vector(char * nF, char * nF1, struct alumno * v);
void vector_a_fichero(char * nF, struct alumno * v, int tam);

#endif