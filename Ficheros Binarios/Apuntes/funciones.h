#ifndef FUNCIONES_H
#define FUNCIONES_H
  struct coche {
        char matricula[10];
        char modelo;
        int plazas;
    };

void mostrarFichero(char * nF);
void addCoche(char * nF, struct coche c);
void modificarFichero(char * nF,char * mat,char * modelo);
/*int buscarProducto (char * nF, char * codigo);
void mediaPrecio (char * nF, float * media);//MEDIA POR REFERENCIA
int contarRegistros(char * nF);
int modificarPrecio(char * nF, char * codigo, float precio);//SI ENCUENTRA EL PRODUCTO Y CAMBIA DEVUELVE UN 1 Y SI NO UN 0
int borrarProducto(char * nF, char * codigo); //SI ENCUENTRA EL PRODUCTO Y BORRA DEVUELVE UN 1 Y SI NO UN 0
int venderProducto (char * nF, char * codigo,int unidades );//paso codfgo y unidades y te devuelve las que quedan, si no hay unidades suficientes devuelve 0
void dividirProductos (char * nF1, char * nF2);//separar en dos ficheros en el otro donde en uno estan los producgos sin unidades
*/
#endif