#include "funciones.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mostrarVector(struct dato * v, int tam);
int comprobarListas(struct lista * lista,struct dato * v);

int main()
{
    struct dato v[] = {
        {1111,1.5},
        {2222,5.3},
        {3333,0.5},
        {4444,4.9},
        {5555,2.9}
    };

    struct lista * pila = NULL, * cola = NULL;
    struct dato datosCorrectos1[] = {
        {3333,0.5},
        {1111,1.5}
    };

    struct dato datosCorrectos2[] = {
        {2222,5.3},
        {4444,4.9},
        {5555,2.9}
    };

    printf("\nLOS ELEMENTOS DEL VECTOR SON LOS SIGUIENTES:\n");
    mostrarVector(v,5);

    int cantidad1, cantidad2;
    apartado1(&cantidad1,&cantidad2,v,5,&pila,&cola,2.0);
    if(cantidad1==2 && cantidad2==3 && comprobarListas(pila,datosCorrectos1) && comprobarListas(cola,datosCorrectos2))
        printf("\nAPARTADO 1 CORRECTO\n\n");
    else
        printf("\nAPARTADO 1 INCORRECTO\n\n");

    int tam1,tam2;
    apartado2(&tam1,cola);
    apartado2(&tam2,pila);
    if(tam1==3 && tam2==2)
        printf("\nAPARTADO 2 CORRECTO\n\n");
    else
        printf("\nAPARTADO 2 INCORRECTO\n\n");
    return 0;
}

void mostrarVector(struct dato * v, int tam)
{
    for (size_t i = 0; i < tam; i++)
    {
        printf("Codigo: %d Peso: %.2f\n",v[i].codigo,v[i].peso);
    }
}

int comprobarListas(struct lista * lista,struct dato * v)
{
    int i=0;
    struct lista * aux = lista;
    while(aux!=NULL)
    {
        if((aux->elemento).codigo != v[i].codigo || (aux->elemento).peso != v[i].peso)
            return 0;
        i++;
        aux=aux->siguiente;
    }
    return 1;
}