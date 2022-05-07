#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

    if (argc !=2){
        printf("EEERRRROR");
        exit(-1);
    }
    
    char * nF = argv [1];
    int opcion=0;
    printf("¿Qué operacion desea hacer?: \n\n");
    printf("1: Mostrar los productos disponibles.\n");
    printf("2: Calcular la media de los precios.\n");
    printf("3: Contar registros.\n");
    printf("4: Pasar fichero a vector.\n");
    //printf("5: Contar cuantos productos hay en stock.\n");
    //printf("6: Modificar un producto.\n");
    //printf("7: Eliminar un producto.\n");
    //printf("8: Vender un producto.\n");
    scanf("%i", &opcion);
    float media=0;
    struct disco d;

    switch(opcion){
        case 1:
        //MOSTAR FICHERO
        printf("Muesta el fichero: \n");
        mostrarFichero(nF);
        break;

        case 2:
        //MEDIA PRECIO
        mediaPrecio(nF,&media);
        printf("La media del precio es : %f", media);
        break;

        case 3:
        //CONTAR REGISTROS
        printf("El numero de discos registrados es de : %d",contarRegistros(nF));
        break;

        case 4:
        //PASAR FICHERO A VECTOR
        fichero_a_Vector(nF,&d);
    }
    //int tam = contarRegistros (nombreFichero);
    //v = reservaMemoria (tam);

    //fichero_a_vector(nombreFichero,v);
    //vector_a_fichero ("fichero2.txt",v,tam);
    //liberarMemoria(&v)
    return 0;
}