#ifndef ESTRUCTURA
#define ESTRUCTURA
struct actor {
    char nombre [50];
    int cache;
    int humano;
    char color[15];

};
#endif

#ifndef FICHERO_H
#define FICHERO_H

int contarActores(char * nF); //AQUÍ ESTABA MAL EL PROTOTIPO, COMO TE HE PUESTO ANTES LE TIENES QUE PASAR NADA MÁS QUE UN FICHERO A CONTAR
void mostrarFichero(char * nF);


#endif