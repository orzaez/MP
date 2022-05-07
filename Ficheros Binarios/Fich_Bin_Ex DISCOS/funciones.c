#include "funciones.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void mostrarFichero (char * nF){
    FILE * fich = fopen(nF, "rb");
    if (fich==NULL){
        printf("Error al abrir el fichero binario");
        exit (-1);
    }
    struct disco d;
    while (fread(&d, sizeof(struct disco),1,fich)==1){
        printf("Codigo: %i \n Nombre: %s\n Autor: %s\n Unidades: %i\n\n", d.cod,d.nombre,d.autor,d.unidades);
    }
    fclose(fich);
}
int contarDiscos(char * nF, struct disco d){
    FILE * fich = fopen(nF, "rb");
    if (fich==NULL){
        printf("Error al abrir el fichero binario");
        exit (-1);
    }
    fseek(fich,0,SEEK_END);
    double nbyte=ftell(fich);
    int tam = nbyte /sizeof(struct disco);
    fclose(fich);
    return tam;
}
void altaDisco (char * nF, struct disco d){
   FILE * fich = fopen(nF, "ab");
    if (fich==NULL){
        printf("Error al abrir el fichero binario");
        exit (-1);
    } 

    fwrite(&d,sizeof(struct disco),1,fich);
    fclose(fich);
}
int incrementarUnidades (char * nF,int codigo, int  unidades){
    FILE * fich = fopen(nF, "rb+");
    if (fich==NULL){
        printf("Error al abrir el fichero binario");
        exit (-1);
    } 
    struct disco d;
    int modificado = -1;

    while(fread(&d,sizeof(struct disco),1,fich)==1){
        if (codigo==d.cod){
            d.unidades=unidades;
            fseek(fich,-1*sizeof(struct disco),SEEK_CUR);
            fwrite(&d,sizeof(struct disco),1,fich);
            modificado =1;
        }
    }
    fclose(fich);
    return modificado;
}



