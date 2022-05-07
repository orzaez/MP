#include "vector.h"
#include "fichero.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct actor * reservaMemoria(int tam){
    struct actor * a = NULL;
    a = (struct actor *) malloc (sizeof (struct actor)*tam);
        if (a == NULL){
            exit(-1);
        }
        
        return a;
        
} 
void liberarMemoria(struct actor **a){
   free(*a);
    (*a)=NULL;
}
void fichero_a_vector(char * nF,long tam){
    FILE * fich = fopen(nF, "rb");
    if (fich == NULL){
        printf("Errror");
        exit(-1);
    }
    struct actor * a;
    tam=contarActores(nF,*a);
    a = reservaMemoria(tam);
    fread(a,sizeof(struct actor),tam,nF);
    fclose(fich);
    return (a);

}
void vector_a_fichero(char * nF, struct actor a, long tam){
    FILE * fich = fopen(nF, "wb");
    if (fich == NULL){
        printf("Errror");
        exit(-1);
    }
    fwrite(&a,sizeof(struct actor),tam,fich);
    printf("Nombre: %s\n Caché: %i\n Humano: %i\n Color: %s\n", a.nombre,a.cache,a.humano,a.color);  
    fclose(fich);
}
