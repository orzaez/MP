#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv)
{
    if(argc != 4)
    {
        printf("Error en línea de argumentos, debes introducir el nombre de 3 ficheros.\n");
        exit(-1);
    }

    char * nf1 = argv[1];
    char * nf2 = argv[2];
    char * nf3 = argv[3];

    if(existeFichero(nf1)==0)
    {
        printf("El fichero %s no existe, debe introducir el nombre de un fichero válido.\n",nf1);
        exit(-1);
    }
    else
    {
        printf("El fichero %s existe.\n",nf1);
    }

    if(existeFichero(nf2)==0)
    {
        printf("El fichero %s no existe, debe introducir el nombre de un fichero válido.\n",nf2);
        exit(-1);
    }
    else
    {
        printf("El fichero %s existe.\n",nf2);
    }

    printf("Uniendo los ficheros...\n");
    unirFicheros(nf1,nf2,nf3);

    return 0;
}