#include "fichero.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 int main(int argc, char ** argv){
    if (argc!=2){
        printf("Error");
        exit(-1);
    }

    char * nF = argv[1];
    char * nF1 = argv[2];
    struct actor * a;
    int tam = contarActores(nF); //PARA QUÉ LE PASAS *a A LA FUNCIÓN QUE CUENTA????
    a = reservaMemoria (tam);
    printf("En este registro hay %i actores\n", tam); //SI ya has calculado el tamaño para que vuelves a llamar a la función??
    fichero_a_vector(nF,a);
    vector_a_fichero("fichero2.bin",a,tam);//LOS VECTORES NUNCA SE PASAN CON * MIGUEL, TU PASAS EL VECTOR Y YA, POR ESO TE SOBRA EL *, ADEMÁS TIENES QUE PONER OTRO FICHERO PARA NO MACHACAR EL QUE TENÍAS
    mostrarFichero("fichero2.bin");//LO VOY A MOSTRAR PARA VER QUE HA FUNCIONADO
    bin_a_txt("actor.txt",a,tam);
    liberarMemoria(&a);

    return 0;
 }