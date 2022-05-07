#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void mostrarFichero(char * nF){
    //ABRIMOS EL FICHERO EN MODO LECTURA "r"
    FILE * fich = fopen (nF,"r");
    if ( fich == NULL ){
        printf ("ERROR AL ABRIR EL FICHERO EN LA FUNCION MOSTRAR FICHERO");
        exit(-1);
    }
    //PROCESO EL FICHERO 
    struct producto p;
    while (fscanf(fich, "%s %f %i", p.codigo, &p.precio, &p.unidades)==3){//aspersan en fscanf scanf
        printf("CODIGO: %s PRECIO: %f UNIDADES: %i \n", p.codigo, p.precio, p.unidades);
    }
    //CERRAR
    fclose(fich);
}
void anadirProducto (char * nF, struct producto p){
    FILE * fich = fopen (nF,"a");
    if (fich == NULL){
        printf("ERROR AL ABRIR EL FICHERO EN LA FUNCION ANADIR PRODUCTO");
        exit(-1);
    }
    fprintf (fich, "%s %f %i\n", p.codigo, p.precio, p.unidades);
    fclose(fich);
}
int buscarProducto (char * nF, char * codigo){
    FILE * fich = fopen (nF,"r");
    if (fich == NULL){
        printf("ERROR AL ABRIR EL FICHERO EN LA FUNCION ANADIR PRODUCTO");
        exit(-1);
    }
    struct producto p;
    while (fscanf(fich, "%s %f %i",p.codigo,&p.precio, &p.unidades)==3){
        if (strcmp(codigo,p.codigo)==0){
            fclose(fich);
            return 1;
        }
    }
    return 0;
    fclose(fich);
}
void mediaPrecio (char * nF, float * media){
    FILE * fich = fopen (nF,"r");
    if (fich == NULL){
        printf("ERROR AL ABRIR EL FICHERO EN LA FUNCION ANADIR PRODUCTO");
        exit(-1);
    }
    struct producto p;
    float suma=0;
    int tam = 0;
    while (fscanf(fich, "%s %f %i",p.codigo,&p.precio, &p.unidades)==3){
        suma = suma + p.precio;
        tam++;
    }
    (*media) = suma/tam;
    fclose(fich);
}
int contarRegistros(char * nF){
    FILE * fich = fopen (nF,"r");
    if (fich == NULL){
        printf("ERROR AL ABRIR EL FICHERO EN LA FUNCION ANADIR PRODUCTO");
        exit(-1);
    }
    struct producto p;
    int cont=0;
    while(fscanf(fich, "%s %f %i",p.codigo,&p.precio, &p.unidades)==3){
        cont++;
    }
    fclose(fich);
    return cont;
}
int modificarPrecio(char * nF, char * codigo, float precio){
    /*Para modificar en un fichero:
    1º Abrimos el fichero original el modo lectura.
    2º Abrimos un fichero auxiliar en modo escritura.
    3º Recorro el fichero original leyendo sus datos y 
    escribiendo dicho datos en el fichero auxiliar. Los datos 
    que quiera modificar los escribo en el auxiliar ya modificados.
    4º Cierro ambos ficheros. 
    5º Borro el fichero original.
    6º Renombro el fichero auxiliar con el nombre original.*/

    //Recibo nota porque quiero cambiar la nota 
    //SI ENCUENTRA EL PRODUCTO Y CAMBIA DEVUELVE UN 1 Y SI NO UN 0
    FILE * fich = fopen (nF, "r");
    if (fich == NULL){
        printf("ERROR AL ABRIR EL FICHERO EN LA FUNCION ANADIR PRODUCTO");
        exit(-1);
    }
    FILE * fich2 = fopen ("ficheroAux.txt", "w");//DESCRIPTOR DEL FICHERO
    if (fich2 == NULL){
        printf ("Error al abrir el fichero auxiliar \n");
        exit(-1);
        fclose (fich);        
    }
    struct producto p;
    int modificado = 0;
    while(fscanf(fich, "%s %f %i",p.codigo,&p.precio, &p.unidades)==3){
        if (strcmp(codigo,p.codigo)==0){
            p.precio=precio;
            modificado=1;
        }
        fprintf(fich2, "%s %f %i\n",p.codigo,p.precio, p.unidades);
    }
    fclose(fich);
    fclose(fich2);
    remove(nF);
    rename("ficheroAux.txt", nF);
    return modificado;
}
int borrarProducto(char * nF, char * codigo){
    //DESCRIPTOR DEL FICHERO
    FILE * fich = fopen (nF, "r");
    if (fich == NULL){
        printf("Eroor al abrir el fichero");
        exit (-1);
    }
    FILE * fich2 = fopen ("ficheroAux.txt", "w");//DESCRIPTOR DEL FICHERO
    if (fich2 == NULL){
        printf ("Error al abrir el fichero auxiliar \n");
        exit(-1);
        fclose (fich);        
    }
    //PROCESAR
    struct producto p;
    int borrado=0;
    while (fscanf(fich,"%s %f %i\n", p.codigo, &p.precio, &p.unidades)==3){
        if (strcmp(codigo,p.codigo)!=0){//NO ENTIENDO LO DE DISTINTO
            fprintf (fich2, "%s %f %i\n", p.codigo, p.precio, p.unidades);
            //printf ("%i", borrado);
        }else{
            borrado=1;
            
        }
    }
    fclose(fich);
    fclose(fich2);
    remove(nF);
    rename("ficheroAux.txt",nF);
    return borrado;

}
int venderProducto (char * nF, char * codigo, int unidades ){
    FILE * fich = fopen (nF,"r");
    if (fich == NULL){
        printf ("Error al abrir el fichero");
        exit (-1);
    }
    FILE * fich2 = fopen ("ficheroAux.txt", "w");//DESCRIPTOR DEL FICHERO
    if (fich2 == NULL){
        printf ("Error al abrir el fichero auxiliar \n");
        exit(-1);
        fclose (fich);        
    }

    struct producto p;
    int vendido=-1;
    while (fscanf(fich, "%s %f %i", p.codigo,&p.precio,&p.unidades)==3){
        if (strcmp(codigo,p.codigo)==0){
            if(p.unidades>=unidades){
                p.unidades=p.unidades-unidades;
                vendido =  p.unidades;
            }
        }
        fprintf(fich2, "%s %f %i\n",p.codigo,p.precio, p.unidades);
        
    }
    fclose(fich);
    fclose(fich2);
    remove(nF);
    rename("ficheroAux.txt", nF);
    return vendido;
    

}
void dividirProductos (char * nF, char * nF1){
    FILE * fich = fopen (nF, "r");
    if (fich == NULL){
        printf("Error al el fichero1");
        exit (-1);

    }

    FILE * fich2 = fopen (nF1, "w");
    if (fich2 == NULL){
        printf("Error al el fichero2");
        exit (-1);
        fclose(fich);
    }
    
    FILE * fich3 = fopen ("ficheroaux.txt", "w");
    if (fich == NULL){
        printf("Error al abrir el fichero3");
        exit (-1);
        fclose(fich2);
    }
    struct producto p;
    while(fscanf(fich, "%s %f %i", p.codigo, &p.precio, &p.unidades)==3){
        if (p.unidades==0){
            fprintf(fich2, "%s %f %i", p.codigo, p.precio, p.unidades);
        }else{
            fprintf(fich3, "%s %f %i\n", p.codigo, p.precio, p.unidades);
        }
    }
    fclose(fich);
    fclose(fich2);
    fclose(fich3);
    remove(nF);
    rename("ficheroaux.txt",nF);
}

