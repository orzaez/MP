#ifndef EXAMEN
#define EXAMEN

#define LENGTH 100
struct datos
{
   int codigo;
   char nombre[LENGTH];
};

struct lista
{
   int codigo;
   char nombre[LENGTH];
   struct lista* sig;
};

int ejercicio3(int nEle1, int nEle2, struct datos* C1, struct datos* C2, struct lista ** LP); 

//INCLUYE AQUI LOS PROTOTIPOS DE TUS FUNCIONES


#endif
