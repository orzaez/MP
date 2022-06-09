#include "funciones.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    La función de abajo recibe un vector como primer argumento, el número de elementos del 
    vector como segundo argumento, una lista como tercer argumento y una variable real llamada
    límite como cuarto argumento.

    La función deberá volcar los datos del vector a la lista siguiente respetando las siguientes
    normas:
        1) Solo se volcarán a la lista los elementos del vector cuyo peso sea inferior al 
            limite que se recibe como cuarto argumento.
        2) Los elementos deben quedar en la lista en orden inverso a como se encuentran en el vector.
    
    Además la función debe retornar el número de elementos que se han volcado a la lista.
*/

int ejercicio(struct dato * VECTOR, int NUMELEMENTOS, struct lista ** LISTA, float limite)
{
    vector_a_lista(VECTOR,NUMELEMENTOS,LISTA,limite);
    return -1;
}

void vector_a_lista(struct dato * VECTOR, int NUMELEMENTOS, struct lista ** LISTA, float limite)
{
    
}
