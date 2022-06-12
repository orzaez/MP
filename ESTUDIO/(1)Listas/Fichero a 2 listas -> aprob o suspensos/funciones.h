#ifndef FUNCIONES_H
#define FUNCIONES_H

#define LENGTH 1024

struct alumno
{
    char nombre[LENGTH];
    int curso;
    float nota;
};

struct lista
{
    struct alumno dato;
    struct lista * siguiente;
};

int ejercicio(char * fichero, struct lista ** aprobados, struct lista ** suspensos);

//COMPLETA AQUÍ CON LOS PROTOTIPOS
struct lista * nuevoElemento();
void insertarDetras(struct lista ** ls, struct alumno a);
int contarElementos(struct lista * LS);
void fichero_a_lista(char * fichero, struct lista ** aprobados, struct lista ** suspensos);



#endif