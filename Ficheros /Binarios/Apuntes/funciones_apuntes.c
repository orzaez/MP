#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void addCoche(char * nF, struct coche c){
    FILE * fich = fopen (nF, "ab");
    if (fich == NULL){
        exit(-1);
    }
    fwrite(&c, sizeof(struct coche),1,fich);
    fclose(fich);
}
void mostrarFichero(char *nF){

    FILE * fich = fopen (nF, "ab");
    if (fich == NULL){
        exit(-1);
    }
    struct coche c;
    while (fread(&c, sizeof(struct coche),1,fich)==1){
        printf("Matricula: %s\n",c.matricula);
    }
}
int contarRegistros (char * nF, struct coche c){
    FILE * fich = fopen (nF, "ab");
    if (fich == NULL){
        exit(-1);
    }
    
    //Fucion que nos permite coger un puntero de un fichero y ponerlo donde queramos, en este caso al final
    fseek(fich,0,SEEK_END);//AQUI DESDE EL FINAL 0 BITS TE MUEVES

    /*fseek(fich,0,SEEK_SET);//AQUI DESDE EL PRINCIPIO 0 BITS TE MUEVES
    fseek(fich,0,SEEK_CUR);//AQUI DESDE EL MEDIO 0 BITS TE MUEVES*/

    //FUNCION QUE NOS DA EL TAMAÑO DESDE DONDE ESTA EL HASTA EL PRINCIPIO DEL FICHERO
    double nbyte=ftell(fich);

    //EL TAMAÑO SERA EL NºDEBYTE / LO QUE OCUPA UN COCHE
    int tam = nbyte / sizeof(struct coche);

    fclose(fich);
    return tam;
}

void modificarFichero(char * nF,char * mat,char * modelo){//por matricula
    FILE * fich = fopen (nF, "rb+");
    if (fich == NULL){
        exit(-1);
    }
    struct coche c;
    while (fread(&c, sizeof(struct coche),1, fich)==1){
        if (strcmp(c.matricula, mat)==0){//busco la matricula que le paso
            strcpy(c.modelo,modelo);//asigno a c.modelo el modelo que le he pasado que no seria con c.modelo=modelo
            fseek(fich,-1*sizeof(struct coche), SEEK_CUR);//modificas el de antes IMPORTANTE PORQUE EL Fread pone el puntero en el +1
            fwrite(&c,sizeof(struct coche),1, fich);
        }
    }
    fclose(fich);
}
