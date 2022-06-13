#include "funciones.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main (char argc, char ** argv){
    if (argc =!3){
        printf ("Errorrr");
        exit(-1);
    }
    char * nF = argv[1];
    char * nF1 = argv[2];
    
    int opcion=0;
    printf("Introduzca la opcion que desea realizar:\n");
    printf("1-.Mostrar el fichero.\n");
    printf("2-.Contar ficheros.\n");
    printf("3-.Alta discos.\n");
    printf("4-.Incrementar unidades.\n");
    scanf("%i",&opcion);
    struct disco d;
    switch (opcion){
    case 1: 
        printf ("Muestra el fichero.\n");
        mostrarFichero(nF);
        break;

    case 2: 
        printf ("En en este fichero hay: %i unidades.\n", contarDiscos(nF,d));
        break;

    case 3: 
        //printf ("Introduzca el nombre del disco.\n");
        printf ("Introduzca el codigo del disco:");
        scanf ("%i",&d.cod);

        printf ("Introduzca el nombre del disco:");
        getchar();//Quita un ultimo caracter en este caso 
        fgets(d.nombre,50,stdin);//NO genera ENTER
        //eliminar el /n con strlen

        printf ("Introduzca el autor del disco:");
        fgets(d.autor,50,stdin);

        printf ("Introduzca el unidades del disco:");
        scanf ("%i",&d.unidades);

        altaDisco(nF,d);
        break;

    case 4: 
        printf("Introduzca el codigo de album que desea cambiar las unidades: ");
        scanf("%i",&d.cod);

        printf("Introduzca las unidades de discos que quedan: ");
        scanf("%i",&d.unidades);
        
        int v = incrementarUnidades(nF,d.cod,d.unidades);
        if (v == 1){
            printf("Se han añadido: %i\n", d.unidades);
        

        }else{
            printf("No se ha podido encontrar el producto.");

        }
        break;
    }
    
    return 0;
}
