#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    if(argc!=2)
    {
        printf("Error en línea de argumentos, debe pasar el argumento de un vector obligatoriamente.\n");
        exit(-1);
    }

    int * v = NULL;
    int tam = atoi(argv[1]);
    int menor, mayor;

    printf("Reservando memoria dinámica para %d elementos...\n",tam);
    v = reservaMemoria(tam);

    //- Rellenar el vector usando memoria dinámica.
    printf("Rellenando vector con números aleatorios...\n");
    rellenarVector(v,tam);

    //- Mostrar el vector rellenado.
    printf("Mostrando el vector de forma iterativa:\n");
    mostrarVector(v,tam);

    //- Mostrar el vector de forma inversa usando recursividad.
    printf("Mostrando el vector de forma inversa usando recursividad:\n");
    mostrarVectorInverso(v,tam,0);

    //- Calcular tanto el menor como el mayor del vector de forma recursivad.
    printf("Calculando el mayor y menor elemento del vector de forma recursiva...\n");
    menorMayorRecur(v,tam,&menor,&mayor,0);
    printf("El menor del vector es %d y el mayor es %d\n",menor,mayor);

    printf("Liberando memoria....\n");
    liberarMemoria(&v);

    return 0;
}