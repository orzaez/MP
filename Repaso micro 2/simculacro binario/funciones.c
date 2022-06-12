#include "funciones.h"
void dividir(char * nF, char *nF1, char * nF2, int prioridad){
    FILE * fich = fopen(nF, "rb");
    if (fich == NULL){
        printf ("Error");
        exit(-1);
    }
    FILE * fich1 = fopen(nF1, "wb");
    if (fich1 == NULL){
        printf ("Error");
        fclose(fich);
        exit(-1);
    }
    FILE * fich2 = fopen(nF2, "wb");
    if (fich2 == NULL){
        printf ("Error");
        fclose(fich);
        fclose(fich1);
        exit(-1);
    }
    struct proceso c;
    while (fread(&c,sizeof(struct proceso),1,fich)==1){
        if (prioridad>=c.prioridad){
            fwrite(&c,sizeof(struct proceso),1,fich1);
        }
        if (prioridad<c.prioridad){
            fwrite(&c,sizeof(struct proceso),1,fich2);
        }
    
    }
    fclose(fich);
    fclose(fich1);
    fclose(fich2);

    }
void mostrarFichero(char * nF){
    FILE * fich= fopen(nF, "rb");
    if (fich == NULL){
        printf ("Error");
        exit(-1);
    }
   struct proceso c;
    while (fread(&c,sizeof(struct proceso),1,fich)==1){
        printf("Nombre: %s\n Duracion: %i\n Prioridad: %i\n\n", c.nombre,c.duracion,c.prioridad);
        
        }
    fclose(fich);
    
    }
int comprobarFichero (char * nF){
    
    FILE * fich = fopen(nF, "rb");
    if (fich == NULL){
        return 0;
    }
    fclose(fich);
    return 1;
}
void borrarRegistro (char * nF, int prioridad){
    FILE * fich = fopen(nF, "rb");
    if (fich == NULL){
        printf("Error al abrir el fichero\n");
        exit(-1);
    }
    FILE * fich1 = fopen("ficheroAux.bin", "wb");
    if (fich1 == NULL){
        printf("Error al abrir el fichero\n");
        fclose(fich);
        exit(-1);
    }
    struct proceso c;
    while (fread(&c,sizeof(struct proceso),1,fich)==1){
        if (prioridad != c.prioridad){
            fwrite(&c,sizeof(struct proceso),1,fich1);
        }
    }
    fclose(fich);
    fclose(fich1);
    remove(nF);
    rename("ficheroAux.bin",nF);
}
int contarRegistros (char * nF){
    FILE * fich = fopen(nF,"rb");
    if (fich == NULL){
        printf ("Error");
        exit(-1);
    }
    struct proceso c;    
    
    fseek(fich,0,SEEK_END);
    double nbyte = ftell(fich);
    int tam = nbyte/sizeof(struct proceso);
    fclose(fich);
    return tam;
    
}
void anadirFichero(char * nF,struct proceso p){
    FILE * fich = fopen(nF,"ab");
    if (fich == NULL){
        printf ("Error");
        exit(-1);
    }
    fwrite(&p,sizeof(struct proceso),1,fich);
    fclose(fich);    

}