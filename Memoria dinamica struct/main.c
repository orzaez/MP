#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){//esto es para cuando ejecuto ./a.out le tengo que pasar el numero que corresponda
    if (argc !=2){
        printf (" Error linea argumento. \n");
        exit(-1);
    }
    int tam = atoi(argv[1]);
    struct persona *v= NULL;
    float media;

    v = reservaMemoria(tam);
    rellenarVector(v,tam);
    mediaEdad(v,tam,&media);
    printf ("La media es %f\n",media);
    liberaMemoria(&v);
    return 0;

}