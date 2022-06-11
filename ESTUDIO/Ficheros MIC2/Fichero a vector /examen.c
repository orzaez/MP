/*------------------------------------------------------------------*/
/* NOMBRE Y APELLIDOS:    se compila gcc main.c examen.c funciones.o                                          */
/* DNI:                                                             */
/*------------------------------------------------------------------*/
#include "funciones.h"
#include "examen.h"

/*------------------------------------------------------------------*/
//HAZ AQUI LOS INCLUDE QUE CONSIDERES NECESARIOS
/*------------------------------------------------------------------*/


/*------------------------------------------------------------------*/
/*Apartado1:
	nEle: número de elementos del vector. Devuelto POR REFERENCIA, hay que calcular su valor.
	nombreFichAlumnos: Nombre del fichero de alumnos.
	nombreFichNotas: Nombre del fichero de notas.
	VALOR DEVUELTO: Vector de struct alumno que debes reservar y rellenar con los datos de los ficheros.
*/
/*------------------------------------------------------------------*/
struct alumno* apartado1(int* nEle, char* nombreFichAlumnos, char* nombreFichNotas)
{
	//INCLUYE AQUI EL CODIGO NECESARIO PARA RESOLVER EL EJERCICIO
  	//NO TE OLVIDES DE HACER EL RETURN
	//NI DE DEVOLVER POR REFERENCIA EL NUMERO DE ELEMENTOS DEL VECTOR
	//RESERVO MEMORIA PARA EL VECTOR DONDE VOY A GUARDAR LOS FICHEROS
	struct alumno * v = NULL;
    //RESERVO MEMORIA
	(*nEle)=contarRegistros(nombreFichNotas);
	printf("Tam = %d\n",*nEle);
    v = reservaMemoria (*nEle);
	fichero_a_vector(nombreFichAlumnos,nombreFichNotas,v);

  return v;
}
struct alumno * reservaMemoria(int nEle){
    struct alumno * v = NULL;
    v = (struct alumno *)malloc(sizeof(struct alumno)*nEle);
    if (v == NULL){
        printf("Error al reservar memoria\n");
        exit(-1);
    }
    return v;
}
int contarRegistros(char * nombreFichNotas){
	FILE * f = fopen (nombreFichNotas, "r");
	if (f==NULL){
		printf("Error al abrir el fichero\n");
        exit(-1);
	}
	int cont=0;
	struct alumno a;
    long dni;
    float nota1, nota2, nota3;   
	while(fscanf(f,"%ld %f %f %f", &a.dni,&nota1,&nota2,&nota3)==4){
		cont++;
	}
	fclose(f);
	return cont;
	printf("cont=%d\n",cont);

}
void fichero_a_vector (char * nombreFichAlumnos, char * nombreFichNotas, struct alumno * v){
	FILE * f = fopen (nombreFichAlumnos, "r");
	if (f==NULL){
		printf("Error al abrir el fichero\n");
		exit(-1);
	}
	FILE * f1 = fopen (nombreFichNotas, "r");
	if (f1==NULL){
		printf("Error al abrir el fichero\n");
        fclose(f1);
	}
	struct alumno a;
    float nota1, nota2, nota3;    

	int i =0;
	while(fgets(a.nombre, MAXLINEA,f)){
		a.nombre[strlen(a.nombre)-1]='\0';
		fscanf(f,"%ld\n",&a.dni);
        fscanf(f1,"%ld %f %f %f", &a.dni,&nota1,&nota2,&nota3);
        a.media = (nota1+nota2+nota3)/3;
        v[i]=a;
        i++;
	}
	fclose(f);
	fclose(f1);
}

/*------------------------------------------------------------------*/
/*Apartado2:
	nEle: número de elementos del vector.
	Vector: Vector ya creado y relleno con los datos de alumnos.
	nombreFichResultado: Nombre del fichero resultado.

*/
/*------------------------------------------------------------------*/
void apartado2(int nEle, struct alumno* Vector, char* nombreFichResultado)
{
     //INCLUYE AQUI EL CODIGO NECESARIO PARA RESOLVER EL EJERCICIO
	vector_a_fichero(nombreFichResultado,Vector,nEle);
}

/*------------------------------------------------------------------*/
//ESCRIBE AQUI TODAS LAS FUNCIONES QUE CONSIDERES NECESARIAS
/*------------------------------------------------------------------*/
void vector_a_fichero(char* nombreFichResultado,struct alumno * Vector, int nEle){
	FILE * f = fopen (nombreFichResultado, "w");
	if (f==NULL){
		printf("Error al abrir el fichero\n");
	}
	for(int i = 0; i<nEle;i++){
		fprintf(f,"%ld %s %f\n", Vector[i].dni ,Vector[i].nombre ,Vector[i].media);
	}
	fclose(f);
}