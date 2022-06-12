#ifndef FUNCIONES_H
#define FUNCIONES_H
struct alumno {
    char dni[10];
    int curso;
    float nota;
};
struct alumno * reservar_memoria (int tam);
void liberaMemoria (struct alumno **v);
void rellenarVector (struct alumno *v, int tam);
int buscarAlumno (struct alumno *v,int tam, char * dni);

#endif