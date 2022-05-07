#ifndef FUNCIONES_H
#define FUNCIONES_H
struct disco {
    int cod;//Código del disco
    char nombre[50];//Nombre del disco
    char autor[50];//Autor del disco
    int unidades; // Numero de unidades vendidas del disco

};

void mostrarFichero (char * nF);
int contarDiscos(char * nF, struct disco d);
void altaDisco (char * nF, struct disco d);
int incrementarUnidades ( char * nF,int  codigo, int  unidades);

#endif 