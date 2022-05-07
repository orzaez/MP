#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//ESTE EJERCICIO TIENE QUE UNIR DOS FICHERO EN UNO SOLO
//RECIBE 4 ARGUMENTEOS /a.out alumnos.txt notas.txt unido.txt

int main(int argc, char **argv){
    //CONTROL DE ERRORES
    if (argc!=4){
        printf("ERROR");
        exit (-1);
    }
    
    //DECLARO LOS FICHEROS 
    char * nF = argv[1];
    char * nF2 = argv[2];
    char * nF3 = argv[3];

    //CONTAR FICHEROS CON EL DE NOTAS PORQUE ES EL MAS FACIL f2
    int tam = contarRegistros (nF3);
    printf("%d", tam);

   //CREO EL VECTOR
    struct alumno * v = NULL;
    //RESERVO MEMORIA
    v = reservaMemoria (tam);

    //PASO DE FICHERO A VECTOR 
    //PARA UNIR LOS DOS FICHEROS, recibe los ficheros a unir y los une en v
    fichero_a_vector(nF,nF2,v);

    //PASO DE VECTOR A FICHERO PARA PONER EL FICHERO UNIDO
    vector_a_fichero (nF3,v,tam);


    liberarMemoria(&v);
    return 0;
}