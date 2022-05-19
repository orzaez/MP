#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int existeFichero(char * nf)
{
    FILE * fich = fopen(nf,"r");
    if(fich==NULL)
    {
        return 0;
    }
    fclose(fich);
    return 1;
}

void unirFicheros(char * nf1, char * nf2, char *nf3)
{
    FILE * fich1 = fopen(nf1,"r");
    if(fich1==NULL)
    {
        printf("Error al abrir el fichero %s en la función unirFicheros()\n",nf1);
        exit(-1);
    }
    FILE * fich2 = fopen(nf2,"r");
    if(fich2==NULL)
    {
        printf("Error al abrir el fichero %s en la función unirFicheros()\n",nf2);
        fclose(fich1);
        exit(-1);
    }
    FILE * fich3 = fopen(nf3,"w");
    if(fich3==NULL)
    {
        printf("Error al abrir el fichero %s en la función unirFicheros()\n",nf3);
        fclose(fich1);
        fclose(fich2);
        exit(-1);
    }

    char nombre[100], apellido1[100], apellido2[100];
    int edad, bilingue;

    while(fscanf(fich1,"%s %s %s %d %d",nombre,apellido1,apellido2,&edad,&bilingue)==5)
    {
        if(bilingue==1)
        {
            fprintf(fich3,"%s %s %s %d %d\n",nombre,apellido1,apellido2,edad,bilingue);
        }
    }

    while(fscanf(fich2,"%s %s %s %d %d",nombre,apellido1,apellido2,&edad,&bilingue)==5)
    {
        if(bilingue==1)
        {
            fprintf(fich3,"%s %s %s %d %d\n",nombre,apellido1,apellido2,edad,bilingue);
        }
    }

    fclose(fich1);
    fclose(fich2);
    fclose(fich3);
}