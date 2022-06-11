#ifndef FUNCIONES_H
#define FUNCIONES_H

struct disco {
    char autor [200];
    char nombre [200];
    float precio;
    int unidades;
};

void mostrarFichero(char * nF); //funcion generica
void mediaPrecio(char * nF, float * media);
int contarRegistros (char * nF);
void fichero_a_Vector (char * nF,struct disco * d);

#endif

/*
void mostrarVector (struct disco * v, int tam);
void ordenarVectorPrecio(struct disco * v, int tam);
void vector_a_fichero(char * nF, struct disco * v, int tam);
void productoMasCaro(char * nF, struct disco * p)*/
