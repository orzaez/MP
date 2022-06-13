#include "funciones.h"

/*//TE COMENTO ESTA FUNCION PORQUE CREO QUE NO LA PEDIAN
void bin_a_txt(char * nF, struct producto * p, long tam){
    FILE * fich = fopen(nF, "w");
    if (fich == NULL){
        printf("Errror");
        exit(-1);
    }
    for(int i =0; i<tam; i++){
        //fwrite(&a[i],sizeof(struct actor),1,fich);
        fprintf(fich, "Nombre: %s\n Caché: %i\n Humano: %i\n Color: %s\n", a[i].nombre,a[i].cache,a[i].humano,a[i].color);  

    }
    fclose(fich);
}*/


long contarregistros(char*nombre){
    FILE * fich = fopen(nombre, "rb");
    if (fich==NULL){
        printf("Error a la abrir el fichero. CONTAR REGISTROS");
        exit (-1);
    }
    fseek (fich, 0, SEEK_END);
    double nbyte=ftell(fich);
    int tam = nbyte / sizeof(struct producto );
    fclose(fich);
    return tam;
}
long contarregistros(char*nombre){
    FILE * fich = fopen(nombre, "rb");
    if (fich==NULL){
        printf("Error a la abrir el fichero. CONTAR REGISTROS");
        exit (-1);
    }
    fseek (fich, 0, SEEK_END);
    double nbyte=ftell(fich);
    int tam = nbyte / sizeof(struct producto );
    fclose(fich);
    return tam;
}
struct producto*reservarMemoria(long nele){
    struct producto * p = NULL;
    p = (struct producto *) malloc (sizeof (struct producto)*nele);
        if (p == NULL){
            exit(-1);
        }
        printf("Se ha reservador memoria\n");
        return p;
}
struct producto*ficheroaVector(char*nombre,struct producto*v){
    FILE * fich = fopen(nombre, "rb");
    if (fich==NULL){
        printf("Error a la abrir el fichero. FICHERO A VECTOR");
        exit (-1);
    }
    struct producto p;
    int i=0;
    while(fread(&p,sizeof(struct producto),1,fich)){
        v[i]=p;
        i++;
    }
    fclose(fich);
    return v;
}
void vectorAtexto(char * nombre, struct producto * v){

}


void unificarFichero(char*nombre1, char*nombre2, char*nombre3, struct producto*v1,struct producto*v2){
    FILE * fich1 = fopen(nombre1, "w");
    if (fich1==NULL){
        printf("Error a la abrir el fichero. CONTAR REGISTROS");
        exit (-1);
    } 
    FILE * fich2 = fopen(nombre2, "w");
    if (fich2==NULL){
        printf("Error a la abrir el fichero. CONTAR REGISTROS");
        exit (-1);
    }
   
    struct producto p;
    

}

void liberarMemoria(struct producto **p){
   free(*p);
    (*p)=NULL;
}
