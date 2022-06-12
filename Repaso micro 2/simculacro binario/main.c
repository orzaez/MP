#include "funciones.h"
int main(int argc, char ** argv){
    if (argc != 4){
        printf ("Error");
        exit (-1);
    }
    char * nF = argv[1];
    char * nF1 = argv[2];
    char * nF2 = argv[3];
    char * nF3 = argv[4];
    int prioridad = 0 ;
    struct proceso c;
    if (comprobarFichero(nF)==1){
        printf("Existe el fichero.\n");
    }else{
        printf("No existe el fichero.\n");
    }
    printf("En este fichero hay %d registros.\n",contarRegistros(nF));

    printf("Introduzca la prioridad:");
    scanf("%d",&prioridad);
    dividir(nF,nF1,nF2,prioridad);
    printf("---Fichero 1:----\n");
    mostrarFichero(nF1);
    printf("----Fichero 2:----\n");
    mostrarFichero(nF2);
    
    printf("Introduzca la prioridad de los procesos que se vayan a eliminar:");
    scanf("%d",&prioridad);
    borrarRegistro(nF,prioridad);
    printf("---Fichero 1:----\n");
    mostrarFichero(nF1);
    printf("----Fichero 2:----\n\n");
    mostrarFichero(nF2);

    printf("Introduzca el nombre del proceso a añadir:");
    getchar();//Quita un ultimo caracter en este caso 
    fgets(c.nombre,15,stdin);
    printf("Introduzca la duracion del proceso a añadir:");
    scanf("%i",&c.duracion);
    printf("Introduzca la prioridad del proceso a añadir:");
    scanf("%i",&c.prioridad);
    anadirFichero(nF,c);
    mostrarFichero(nF);




    return 0;
}