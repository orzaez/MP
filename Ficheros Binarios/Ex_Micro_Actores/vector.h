#ifndef VECTOR_H
#define VECTOR_H

struct actor * reservaMemoria(int tam);
void liberarMemoria(struct actor **a);

void fichero_a_vector(char * nF,long tam);
void vector_a_fichero(char * nF, struct actor a, long tam);

#endif