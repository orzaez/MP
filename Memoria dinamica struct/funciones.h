#ifndef FUNCIONES_H
#define FUNCIONES_H
struct persona{
    char nombre [100];
    char apellido [200];
    int edad;
};
struct persona * reservaMemoria(int tam);
void rellenarVector (struct persona *v, int tam);
void mediaEdad(struct persona * v, int tam , float * media );
void liberaMemoria(struct persona **v);

#endif