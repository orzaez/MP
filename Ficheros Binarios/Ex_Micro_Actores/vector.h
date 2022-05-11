
#ifndef VECTOR_H
#define VECTOR_H

struct actor * reservaMemoria(int tam);
void liberarMemoria(struct actor **a);
void fichero_a_vector(char * nF,struct actor * v);
void vector_a_fichero(char * nF, struct actor * v, long tam);
void bin_a_txt(char * nF, struct actor * a, long tam);


#endif