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

int contarActores(char * nF,struct actor a);
#endif