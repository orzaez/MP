#ifndef FUNCIONES_H
#define FUNCIONES_H
  struct nodo {
        int dato;//cabeza
        struct nodo * sig;//Flecha
    };
    
struct nodo * nuevoElemento();
void insertarDelante(struct nodo **cabeza, int dato );
void mostrarLista(struct nodo * cabeza);
int contarLista(struct nodo * cabeza);
void insertarDetras(struct nodo ** cabeza, int dato);
void borrarLista(struct nodo ** cabeza);
void borrarNodo(struct nodo ** cabeza, int dato);



#endif