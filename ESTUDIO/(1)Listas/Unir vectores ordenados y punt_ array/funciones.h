#ifndef FUNCIONES_H
#define FUNCIONES_H

#define LENGTH 100

struct dato
{
    char nombre[LENGTH];
    int codigo;
    double longitud;
};

struct dato * ejercicio(struct dato * v1,struct dato * v2,int tam1, int tam2, int * tam);

//COMPLETA AQUÍ CON LOS PROTOTIPOS
struct dato * reservaMemoria(int tam);
void unirVectores(struct dato * v1, struct dato * v2,int tam1, int tam2,struct dato * unido);
//void ordenaVector(struct dato * v, int tam);
int ordenaVector(const void * e1, const void * e2);


#endif