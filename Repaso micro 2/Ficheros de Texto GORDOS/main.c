#include "fichero.h"

int main(int argc, char ** argv){
    if (argc!=2){
        printf ("Error en el paso de argumentos");
        exit(-1);
    }
    char * nF = argv[1];
    struct disco * v=NULL;

    int tam=contarRegistros(nF);
    printf("%i\n",contarRegistros(nF));
    reservaMemoria(tam);
    v = reservaMemoria (tam);

    mostrarFichero(nF);

    ficheroAvector(nF,v);
    liberarMemoria(&v);
    
    return 0;

}