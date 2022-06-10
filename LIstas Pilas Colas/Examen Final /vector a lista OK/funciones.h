#ifndef FUNCIONES_H
#define FUNCIONES_H

struct dato
{
    int codigo;
    float peso;
};

struct lista
{
    struct dato elemento;
    struct lista * siguiente;
};

void apartado1(int * tam1, int * tam2, struct dato * VECTOR, int NUMELEMENTOS, struct lista ** LISTA1,  struct lista ** LISTA2, float PESO);

void apartado2(int * tam, struct lista * LISTA);

//COMPLETA AQUÍ CON EL PROTOTIPO DE LAS FUNCIONES QUE HAYAS CREADO
struct lista * nuevoElemento();
void insertarDelante(struct lista **LISTA1,struct dato VECTOR);
void insertarDetras(struct lista **LISTA2,struct dato VECTOR);

void vector_a_lista(struct lista **LISTA1,struct lista **LISTA2,struct dato *VECTOR,int NUMELEMENTOS,float limite,int * tam1, int *tam2);
#endif