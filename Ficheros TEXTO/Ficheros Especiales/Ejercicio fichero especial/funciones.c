#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//LOS DATOS EN UN FICHERO DE FORMA RARA
struct disco d;
void mostrarFichero(char * nF){

    FILE * fich = NULL;
    fich = fopen (nF, "r");
    if (fich == NULL){
        printf ("ERROR AL ABRIR EL FICHERO EN LA FUNCION MOSTRAR FICHERO");
        exit(-1);
    }
    //proceso
    while(fgets(d.autor,200,fich)){
        d.autor[strlen(d.autor)-1]='\0';//
        d.nombre[strlen(d.nombre)-1]='\0';//
        fgets(d.nombre,200,fich);
        fscanf(fich, "%f %d\n",&d.precio, &d.unidades);      //Accion de la funcion;
        printf("Autor: %s\n Nombre: %s \n Precio: %f \n Unidades: %i \n",d.autor, d.nombre, d.precio, d.unidades);
    }
    fclose(fich);
}
void mediaPrecio(char * nF, float * media){
    FILE * fich = fopen(nF, "r");
    if (fich == NULL){
        printf("ERROR");
        exit (-1);
    }
    int suma=0;
    int tam=0;
    while(fgets(d.autor,200,fich)){
        fscanf(fich,"%f",&d.precio);
        suma = suma + d.precio;
        tam++;
    }
    (*media)= suma /tam;
    fclose(fich);
}
int contarRegistros (char * nF){
    FILE * fich = fopen(nF, "r");
    if (fich == NULL){
        printf("ERROR");
        exit(-1);
   }
   int cont=0;
   while(fgets(d.autor,200,fich)){
       d.autor[strlen(d.autor)-1]='\0';//
        d.nombre[strlen(d.nombre)-1]='\0';//
        fgets(d.nombre,200,fich);
        fscanf(fich, "%f %d\n",&d.precio, &d.unidades);
        cont ++;
   }
   return cont;
   fclose(fich);
}
void fichero_a_Vector (char * nF,struct disco * v){
    FILE * fich = fopen(nF, "r");
    if (fich == NULL){
        printf ("ERROR AL ABRIR EL FICHERO1 EN LA FUNCION MOSTRAR FICHERO");
        exit(-1);
    }
    int i = 0;
    struct disco d;
    while(fgets(d.autor,200,fich)){
        d.autor[strlen(d.autor)-1]='\0';//
        d.nombre[strlen(d.nombre)-1]='\0';//
        fgets(d.nombre,200,fich);
        fscanf(fich, "%f %d\n",&d.precio, &d.unidades); 
        v[i]=d;
        i++;
    }
    fclose(fich);

}

/*void fichero_a_vector(char * nF, struct producto * v){
    //leer el fichero
    FILE * fich = fopen(nF, "r");
    if (fich = NULL){
        printf ("ERROR AL ABRIR EL FICHERO1 EN LA FUNCION MOSTRAR FICHERO");
        exit(-1);
    }
    struct producto p;
    int i = 0;
    while(fscanf(fich, "%s %f %d",p.codigo, &p.precio,&p.unidades)==3){
        v[i]=p;
        i++;
    }
    fclose(fich);
}*/

/*void vector_a_fichoo(char * nF, struct producto * v){
    //leer el fichero
    FILE * fich = fopen(nF, "r");
    if (fich = NULL){
        printf ("ERROR AL ABRIR EL FICHERO1 EN LA FUNCION MOSTRAR FICHERO");
        exit(-1);
    }
    for (int i = 0;i<tam;i++){
        fprintf(fich, "%s %f %d\n", v[i].codigo,v[i].precio,v[i].unidades);
    }
    fclose(fich);
}*/
//LOS DATOS EN DOS FICHERO
