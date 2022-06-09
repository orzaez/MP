#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * reservaMemoria(int tam)
{
    int * v = NULL;
    v = (int *)malloc(sizeof(int)*tam);
    if(v==NULL)
    {
        printf("Error al reservar memoria\n");
        exit(-1);
    }
    return v;
}

void rellenarVector(int * v,int tam)
{
    srand(time(NULL));
    for (size_t i = 0; i < tam; i++)
    {
        v[i] = rand()%100;
    }
    
}

void mostrarVector(int *v,int tam)
{
    for (size_t i = 0; i < tam; i++)
    {
        printf("%d\n",v[i]);
    }
    
}

void mostrarVectorInverso(int *v,int tam,int i)
{
    if(i<tam)
    {
        mostrarVectorInverso(v,tam,i+1);
        printf("%d\n",v[i]);
    }
}

void menorMayorRecur(int * v,int tam,int * menor,int * mayor, int i)
{
    if(i<tam)
    {
        if(i==0)
        {
            (*menor) = v[0];
            (*mayor)  = v[0];
        }
        else if(v[i]<(*menor))
        {
            (*menor) = v[i];
        }
        else if(v[i]>(*mayor))
        {
            (*mayor) = v[i];
        }
        menorMayorRecur(v,tam,menor,mayor,i+1);
    }
}

void liberarMemoria(int **v)
{
    free(*v);
    (*v) = NULL;
}
