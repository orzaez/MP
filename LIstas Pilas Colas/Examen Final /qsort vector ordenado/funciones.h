/*
    Autor: Academia Main()
    Web: www.academiamain.es
    Contacto:  605 45 70 99 
*/
#ifndef FUNCIONES_H
#define FUNCIONES_H

struct dato
{
    char nombre[100];
    float peso;
    int codigo;
};
//void ordenar(struct dato * v, int tam, int (*nombreFuncion)(struct dato a, struct dato b));

void ejercicio(struct dato * V, int nElementos, int criterio);
int nombreAl(const void * e1, const void * e2);
int peso(const void * e1, const void *e2);
int codigo(const void * e1, const void *e2);

//COMPLETA AQUÍ CON EL PROTOTIPO DE LAS FUNCIONES QUE HAYAS NECESITADO


#endif