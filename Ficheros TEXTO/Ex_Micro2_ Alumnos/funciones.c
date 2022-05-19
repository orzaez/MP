#include "funciones.h"

int contarRegistros(char * nF){

    FILE * fich = fopen(nF, "r");
     if (fich == NULL){
        printf ("ERROR AL ABRIR EL FICHERO1 EN LA FUNCION MOSTRAR FICHERO");
        exit(-1);
    }
    long dni;
    float nota1, nota2, nota3;
    int cont=0;
    /*while (fscanf(fich, "%ld %f %f %f", &dni, &nota1, &nota2, &nota3)==4){
        cont ++;
    }*/
    struct alumno a;
    while(fgets(a.nombre,1000,fich)){
        a.nombre[strlen(a.nombre)-1]='\0';
        fscanf(fich,"%ld\n",&a.dni);
        cont++;
    }

    fclose(fich);
    
    return cont;
}

struct alumno * reservaMemoria(int tam){
    struct alumno * v = NULL;
    v = (struct alumno *) malloc (sizeof (struct alumno)*tam);
        if (v == NULL){
            exit(-1);
        }
        
        return v;
        
} 
    
void liberarMemoria(struct alumno **v){
    free(*v);
    (*v)=NULL;
}

void fichero_a_vector(char * nF, char * nF1, struct alumno * v){
    //LEES Y ABRES LOS DOS FICHEROS 
    FILE * fich = fopen(nF, "r");
    if (fich == NULL){
        printf ("ERROR AL ABRIR EL FICHERO1 EN LA FUNCION MOSTRAR FICHERO");
        exit(-1);
        }
    FILE * fich1 = fopen(nF1, "r");
    if (fich1 == NULL){
        printf ("ERROR AL ABRIR EL FICHERO1 EN LA FUNCION MOSTRAR FICHERO");
        fclose(fich1);
        exit(-1);
    }
    
    struct alumno a;
    //COMO NO TENGO 3 NOTAS EN EL STRUCT TENGO QUE CREARLAS

    float nota1, nota2, nota3;    
    int i =0;
    while(fgets(a.nombre,1000,fich)){//FGETS PORQUE NO SABES CUANTS ESPACIOS HAY EN EL NOMBRE
        a.nombre[strlen(a.nombre)-1]='\0';
        fscanf(fich, "%ld\n", &a.dni);//Leo el fichero1 especial PONGO /N PORQUE HAY FGETS Y SI SIEMPRE SE PONE 
        fscanf(fich1, "%ld %f %f %f", &a.dni, &nota1, &nota2, &nota3);
        a.media = (nota1+nota2+nota3)/3;
        printf("%f\n",a.media);
        v[i]=a;//LA A LLEVA UN DNI NOTA1 NOTA2 NOTA3;
        i++;
    }
    fclose(fich);
    fclose(fich1);
}
void vector_a_fichero(char * nF, struct alumno * v, int tam){
    FILE * fich = fopen(nF,"w");
    if (fich == NULL){
        printf ("ERROR AL ABRIR EL FICHERO1 EN LA FUNCION MOSTRAR FICHERO");
        exit(-1);
    }

    for (int i=0;i<=tam;i++){
        fprintf(fich, "%ld %s %f\n", v[i].dni ,v[i].nombre ,v[i].media);
    }
    fclose(fich);
}
