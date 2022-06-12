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

//INCLUYE AQUI LOS PROTOTIPOS DE TUS FUNCIONEs
int buscarLista(struct lista *LS, int codigo);
void insertarDelante(struct lista ** LS, struct datos  v);
int contarElementos(struct lista * LS);
struct lista * nuevoElemento();
void vector_a_lista(int nEle1, int nEle2, struct datos* A1, struct datos* A2, struct lista ** LS);

#endif
