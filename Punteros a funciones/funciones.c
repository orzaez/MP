#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void ordenar (struct persona * v, int tam, int (*nombreFuncion)(struct persona a,struct persona b)){
    struct persona aux;
    for (int i =0; i<tam; i++){
        for(int j = i+1; j<tam; j++){
            if((*nombreFuncion)(v[i],v[j])==1){
                aux=v[i];
                v[i]=v[j];
                v[j]=aux
            }
        }

    }
}
//en el main NOS LO DA
struct persona * v;
ordenar (v, tam, &edadAscendente);
.
.
.
int edadAscendente(struct persona a, struct persona b){
    if (a.edad > b.edad){
        return 1;
    }
    return 0;
}