#ifndef BINARIO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct proceso{
    char nombre[15];
    int duracion;
    int prioridad;
};
void dividir(char * nF, char *nF1, char * nF2, int prioridad);
void mostrarFichero(char * nF);
int comprobarFichero (char * nF);
void borrarRegistro (char * nF, int prioridad);
int contarRegistros (char * nF);
void anadirFichero(char * nF,struct proceso c);





#endif 



