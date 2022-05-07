
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumno * reservar_memoria (int tam){
    struct alumno * v = NULL;
    v = (struct alumno*) malloc (sizeof (struct alumno)* tam);
    if ( v == NULL) {
        printf("ERROR AL RESERVAR MEMORIA");
        exit (-1);
    } 
    return v;
}
void rellenarVector (struct alumno *v, int tam){
    for (int i=0; i<tam; i++){
        printf ("Introduce el DNI del alumno: ");
        getchar();
        fgets (v[i].dni, 10, stdin);

        printf ("Introduce el curso del alumno: ");
        scanf ("%i", &v[i].curso);

        printf ("Introduce la nota del alumno: ");
        scanf ("%f", &v[i].nota);
        
    }
}
int buscarAlumno (struct alumno *v,int tam, char * dni){
    char dnibuscar;
    printf ("Introduce el DNI del alumno a buscar: ");
    getchar();
    fgets (&dnibuscar, 10, stdin);
    for (int i=0; i<tam; i++){
        if (strcmp(v[i].dni,&dnibuscar)==1){
            printf ("Existe el alumnos");
            return 1;
        }
    }
    return 0;
}

void liberaMemoria (struct alumno **v){
     free(*v);
    (*v)=NULL;
}
