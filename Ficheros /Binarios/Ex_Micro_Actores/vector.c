#include "vector.h"

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
void fichero_a_vector(char * nF,struct actor * v){
    FILE * fich = fopen(nF, "rb");
    if (fich == NULL){
        printf("Errror");
        exit(-1);
    }
    struct actor a;
    int i = 0;
    while(fread(&a,sizeof(struct actor),1,fich)){
        v[i]=a;
        i++;
    }
    fclose(fich);

}
void vector_a_fichero(char * nF, struct actor * a, long tam){
    FILE * fich = fopen(nF, "wb");
    if (fich == NULL){
        printf("Errror");
        exit(-1);
    }
    for(int i =0; i<tam; i++){
        fwrite(&a[i],sizeof(struct actor),1,fich);
        //fprintf(fich, "Nombre: %s\n Caché: %i\n Humano: %i\n Color: %s\n", a[i].nombre,a[i].cache,a[i].humano,a[i].color);   ESTA LINEA NUNCA DEBES PONERLA, TU ESCRIBES EN EL FICHERO, LUEGO LO MUESTRAS

    }
    fclose(fich);
}

void bin_a_txt(char * nF, struct actor * a, long tam){
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
}
