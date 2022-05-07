#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    //printf ("%d", argc);
    if (argc != 3){
        printf("EEEERRROR");
        exit(-1);
    }
    char * nF = argv [1];
    char * nF1 = argv [2];
    int opcion=0;
    printf("¿Qué operacion desea hacer?: \n\n");
    printf("1: Mostrar los productos disponibles.\n");
    printf("2: Añadir un producto.\n");
    printf("3: Buscar un producto.\n");
    printf("4: Calcular la media del precio de los productos.\n");
    printf("5: Contar cuantos productos hay en stock.\n");
    printf("6: Modificar un producto.\n");
    printf("7: Eliminar un producto.\n");
    printf("8: Vender un producto.\n");
    scanf("%i", &opcion);
    struct producto p;
    float media=0;


    switch(opcion){
        case 1:
        //FUNCION MOSTRARFICHERO
            printf("Muestra el fichero: \n");
            mostrarFichero(nF);
            break;

        case 2:
        //FUNCION ANADIRPRODUCTO
            /*struct producto p;
            printf("Introduce el codigo del producto a añadir: \n");
            scanf("%s",p.codigo);
            printf("Introduce el precio a añadir: \n");
            scanf("%f",&p.precio);
            printf("Introduce las unidades a añadir: \n");
            scanf("%i",&p.unidades);
            anadirProducto(nF,p);*/
            break;

        case 3:
        //FUNCION BUSCARPRODUCTO
            printf("Introduce el codigo del producto a buscar: ");
            scanf("%s", p.codigo);
            int buscar = buscarProducto(nF,p.codigo);
            if (buscar == 1){
                printf("El producto ha sido encontrado\n");
            }else{
                printf("El producto no ha sido encontrado\n");
            }
            break;

        case 4:
        //FUNCION MEDIAPRECIO
            mediaPrecio(nF,&media);
            printf("La media de los precios es: %f\n", media);
            break;

        case 5:
        //FUNCION CONTARREGISTROS
            printf("El numero de productos que hay es: %d \n", contarRegistros(nF));
            break;

        case 6:
        //FUNCION MODIFICARPRECIO
            printf("Introduce el codigo del producto a modificar: ");
            scanf("%s",p.codigo);
            printf("Introduce el nuevo precio: ");
            scanf("%f",&p.precio);
            int modificar = modificarPrecio(nF,p.codigo,p.precio);
            if (modificar==1){
                printf("El producto se ha encontrado y se ha modificado correctamnte\n");
            }else{
                printf("El producto no se ha encontrado y no se ha modificado correctamnte\n");
            }
            break;

        case 7:
        //FUNCION BORRARPRODUCTO
            printf ("Introduzca el codigo del producto que desea eliminar: ");
            scanf("%s",p.codigo);
            int borrar = borrarProducto (nF, p.codigo);
            if (borrar == 1){
                printf("El producto se ha borrado correctamente.\n");
            }else{
                printf("El producto no se ha encontrado y por tanto no se ha borrado correctamente\n");
            }
            break;

        case 8:
        //FUNCION VENDERPROCUTO
            printf ("Introduzca el codigo del producto que desea vender: ");
            scanf("%s",p.codigo);
            printf ("Introduzca la cantidad de productos que desea vender: ");
            scanf("%d",&p.unidades);
            int vendido = venderProducto(nF,p.codigo,p.unidades);
            if (vendido == -1){
                printf("El producto no se ha vendido correctamente. \n");
            }else{
                printf("El producto se ha vendido correctamente y quedan en stock %i \n", vendido);
            
            }
            break;

        // operator doesn't match any case constant +, -, *, /
        default:
            printf("Error! operator is not correct");
    }
    //FUNCION DIVIDIRPRODUCTO
        printf("Se procederá a dividir los productos vendidos a otro fichero.\n");
        dividirProductos(nF,nF1);

    return 0;
 
    }