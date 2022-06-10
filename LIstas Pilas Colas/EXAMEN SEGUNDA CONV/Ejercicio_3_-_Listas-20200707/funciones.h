#ifndef EXAMEN
#define EXAMEN

#define LENGTH 100
struct datos
{
   int codigo; //Identificador unico para cada alumno
   char nombre[LENGTH];
   float nota;
};

struct lista
{
   int codigo;
   char nombre[LENGTH];
   struct lista* sig;
};

int ejercicio3(int nEle1, int nEle2, struct datos* A1, struct datos* A2, struct lista ** LS); 

//INCLUYE AQUI LOS PROTOTIPOS DE TUS FUNCIONES

#endif
