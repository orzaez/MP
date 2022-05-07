#include "funciones.h"
#include <string.h>
#include <stdio.h>    
#include <stdlib.h>

void unirFichero(char * nF,char * nF1,char * nF2){
    FILE * fich = NULL;
    fich = fopen (nF, "r");
    if (fich = NULL){
        printf ("ERROR AL ABRIR EL FICHERO1 EN LA FUNCION MOSTRAR FICHERO");
        exit(-1);
    }
    FILE * fich2 = NULL;
    fich2 = fopen (nF2, "r");
    if (fich2 = NULL){
        printf ("ERROR AL ABRIR EL FICHERO2 EN LA FUNCION MOSTRAR FICHERO");
        fclose(fich);
        exit(-1);
    }
    FILE * fich3 = NULL;
    fich3 = fopen ("dato.txt", "w");
    if (fich3 = NULL){
        printf ("ERROR AL ABRIR EL FICHERO3 EN LA FUNCION MOSTRAR FICHERO");
        fclose(fich);
        fclose(fich2);
        exit(-1);
    }
    //proceso sin estructura
    char nombre [1024],asig [1024];
    while(fgets(nombre,1024,fich)){
        p.nombre[strlen(nombre)-1]='\0';//Esto se tiene que hacer antes del proceso de la funcion.
        f.gets(asig,1024,fich2);
        asig [strlen(asig)-1]='\0';
        fprintf(fich3, "%s - %s\n",nombre,asig);
    }
    fclose(fich1);
    fclose(fich2);
    fclose(fich3);
}