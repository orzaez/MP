#include "fichero.h"
#include "vector.h"
int contarActores(char * nF){
    FILE * fich = fopen(nF, "rb");
    if (fich == NULL){
        printf("Errror");
        exit(-1);
    }
    fseek (fich, 0, SEEK_END);
    double nbyte=ftell(fich);
    int tam = nbyte / sizeof(struct actor );
    fclose(fich);
    return tam; 
    }

void mostrarFichero(char * nF){
    FILE * fich = fopen(nF,"rb");
    if(fich==NULL){
        printf("ERROR al abrirl el fichero\n");
        exit(-1);
    }

    struct actor a;
    while(fread(&a,sizeof(struct actor),1,fich)==1){
        printf("El actor se llama %s, tiene una cache de %d, su campo humano vale %d y su color es %s\n",a.nombre,a.cache,a.humano,a.color);
    }
    fclose(fich);
}