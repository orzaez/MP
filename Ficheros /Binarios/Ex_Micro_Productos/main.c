#include "funciones.h"


int main (int * argc, char **argv ){

    if (argc=!3){
        printf("Error");
        exit(-1);
    }

    char * nF = argv[1];
    char * nF1 = argv [2];
    struct producto * p;
    struct producto * p1;

    int nele1=contarregistros(nF);
    int nele2=contarregistros(nF1);
    printf("%i\n",nele1);
    printf("%i\n",nele2);
    
    p = reservarMemoria(nele1);
    p1 = reservarMemoria(nele2);
    ficheroaVector(nF,p);
    ficheroaVector(nF1,p1);



    liberarMemoria(&p);
    liberarMemoria(&p1);



}