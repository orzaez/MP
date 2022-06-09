#ifndef FUNCIONES_H
#define FUNCINOES_H
int * reservaMemoria(int tam);
void rellenarVector(int * v,int tam);
void mostrarVector(int *v,int tam);
void mostrarVectorInverso(int *v,int tam,int i);
void menorMayorRecur(int * v,int tam,int * menor,int * mayor, int i);
void liberarMemoria(int **v);
#endif