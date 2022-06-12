#include "fichero.h"

void mostrarFichero(char * nF){
    FILE * fich = NULL;
    fich = fopen (nF, "r");
    if (fich == NULL){
        printf ("ERROR AL ABRIR EL FICHERO EN LA FUNCION MOSTRAR FICHERO");
        exit(-1);
    }
    struct disco d;
    while(fgets(d.autor,100,fich)){
        d.autor[strlen(d.autor)-1]='\0';
        d.nombre[strlen(d.nombre)-1]='\0';
        fgets(d.nombre,100,fich);
        //getchar();
        fscanf (fich,"%f %i\n", &d.precio,&d.unidades);
        printf ("Autor: %s\n Nombre: %s Precio: %f\n Unidades : %i\n\n", d.autor,d.nombre,d.precio,d.unidades);

    }
    fclose(fich);
}

int contarRegistros(char * nF){
    FILE * fich = NULL;
    fich = fopen (nF, "r");
    if (fich == NULL){
        printf ("ERROR AL ABRIR EL FICHERO EN LA FUNCION MOSTRAR FICHERO");
        exit(-1);
    }
    struct disco d;
    int cont = 0;
    while(fgets(d.autor,100,fich)){
        d.autor[strlen(d.autor)-1]='\0';
        d.nombre[strlen(d.nombre)-1]='\0';
        fgets(d.nombre,100,fich);
        fscanf(fich,"%f %i\n",&d.precio, &d.unidades);
        cont ++;
    }
    fclose(fich);
    return cont;
}
struct disco * reservaMemoria (int tam){
    struct disco * d = NULL;
    d = (struct disco *) malloc (sizeof(struct disco)*tam);
    if (d == NULL){
        exit (-1);
    }else{
        printf("SE HA RESERVADO MEMORIA\n");
    }
        return d;

}
void liberarMemoria(struct disco **d){
    free(*d);
    (*d)=NULL;
    printf("OK");
}

void ficheroAvector(char * nF, struct disco * v){
    FILE * fich = fopen(nF,"r");
    if (fich==NULL){
        exit(-1);
        printf("Error");
    }
    struct disco d;
    int i = 0;
    printf("A");
     while(fgets(d.autor,100,fich)){
    printf("B");

        d.autor[strlen(d.autor)-1]='\0';
        d.nombre[strlen(d.nombre)-1]='\0';
        fgets(d.nombre,100,fich);
        fscanf(fich,"%f %i\n",&d.precio, &d.unidades);
        v[i]=d;
        i++;
        printf("Se ha pasado correctamente");
    }
    fclose(fich);
}