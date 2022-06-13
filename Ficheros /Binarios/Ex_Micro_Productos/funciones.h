#ifndef __MICRO__
#define __MICRO__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct producto{
    char nombre[50];
    int cod;
    float precio;
    int unidades;
};
struct producto*ficheroaVector(char*nombre,struct producto*v);
struct producto*reservarMemoria(long nele1);
long contarregistros(char*nombre);
void liberarMemoria(struct producto **p);
void vectorAtexto(char * nombre, struct producto * v);
int comprueba_ficheros(char*f1,char*f2);
void unificarFichero(char*nombre1, char*nombre2, char*nombre3, struct producto*v1,struct producto*v2);
#endif