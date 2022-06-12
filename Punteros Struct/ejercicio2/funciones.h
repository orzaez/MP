#ifndef FUNCIONES_H
#define FUNCIONES_H
    struct objeto {
        char codigo[10];
        int tipo;
        float peso;
    };
    struct objeto * reservar_memoria (int tam);
    void rellenarVector (struct objeto *o, int tam);
    void comparapeso(struct objeto *o, int tam);

    void liberaMemoria (struct objeto **o);
#endif