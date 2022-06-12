#ifndef FUNCIONES_H
#define FUNCIONES_H
  struct producto {
        char codigo[10];
        float precio;
        int unidades;
    };

void mostrarFichero(char * nF);
void anadirProducto (char * nF, struct producto p);
int buscarProducto (char * nF, char * codigo);
void mediaPrecio (char * nF, float * media);//MEDIA POR REFERENCIA
int contarRegistros(char * nF);
int modificarPrecio(char * nF, char * codigo, float precio);//SI ENCUENTRA EL PRODUCTO Y CAMBIA DEVUELVE UN 1 Y SI NO UN 0
int borrarProducto(char * nF, char * codigo); //SI ENCUENTRA EL PRODUCTO Y BORRA DEVUELVE UN 1 Y SI NO UN 0
int venderProducto (char * nF, char * codigo,int unidades );//paso codfgo y unidades y te devuelve las que quedan, si no hay unidades suficientes devuelve 0
void dividirProductos (char * nF1, char * nF2);//separar en dos ficheros en el otro donde en uno estan los producgos sin unidades

#endif