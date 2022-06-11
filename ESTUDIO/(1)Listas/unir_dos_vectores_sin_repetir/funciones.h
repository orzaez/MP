#ifndef FUNCIONES_H
#define FUNCIONES_H

struct coche
{
    int matricula;
    char marca[100];
    int anio_matriculacion;
};

struct lista
{
    int matricula;
    char marca[100];
    int anio_matriculacion;
    struct lista * siguiente;
};

int ejercicio(struct coche * V1, struct coche * V2, int tam1, int tam2, struct lista ** LS);

//COMPLETA AQUÍ CON LOS PROTOTIPOS QUE HAYAS UTILIZADO
struct coche * reservaMemoria(int tam);
void unirVectores(struct coche * v1, struct coche * v2, int tam1, int tam2, struct coche * unido,int * tamunido);
int buscarCoche(struct coche * unido, int  tam, int matricula);


#endif