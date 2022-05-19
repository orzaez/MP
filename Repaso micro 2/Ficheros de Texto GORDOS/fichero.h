#ifndef REPASO_MICRO
#define REPASO_MICRO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct disco {
    char autor [100];
    char nombre[100];
    float precio;
    int unidades;
};
void mostrarFichero(char * nF);
int contarRegistros(char * nF);
void ficheroAvector(char * nF, struct disco * v);
struct disco * reservaMemoria (int tam);
void liberarMemoria(struct disco **d);




#endif