#ifndef FICHERO_H
#define FICHERO_H
struct actor {
    char nombre [50];
    int cache;
    int humano;
    char color[15];

};
int contarActores(char * nF,struct actor a);
#endif