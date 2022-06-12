#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int imprimirVector(int nEle, struct datos * Vector);
int comprobarLista(struct lista* cabeza, struct datos* Correctos, int nEle);
int indice(struct datos* V, int nEle, int codigo);

int main()
{
   int nEle1 = 5, nEle2=6, nSobresalientes=3, respuesta, comprobacion;
   float acumulada = 0;
   float pesoExamen=0.3;
   float puntosListas=3;   

   struct datos A1[]={{3, "Jose Luis Perez", 7.5},{1, "Sofia Sanchez", 9.5},{7, "Maria Luisa Avila", 4.25},{9, "Mariano Lopez", 8.75},{2, "Alfonso Gomez", 9.35}};
   struct datos A2[]={{7, "Maria Luisa Avila", 6.45}, {4, "Lucia Olmo", 3.75}, {9, "Mariano Lopez", 9.25}, {6, "Umberto Gutierrez", 8.75}, {5, "Alicia Vilches", 5.5}, {2, "Alfonso Gomez", 9.75}};
   struct datos Correctos[]={{2, "Alfonso Gomez", 0.0},{1, "Sofia Sanchez", 0.0},{9, "Mariano Lopez", 0.0}};
 
   struct lista* LS=NULL;
  
   printf("\n\n-----------------------------");
   printf("\nPUNTUACION DEL EJERCICIO 3: LISTAS");
   printf("\n\tTOTAL EJERCICIO (sobre 10): %.3f puntos", puntosListas);
   printf("\n\tTOTAL NOTA FINAL(sobre 3) : %.3f puntos", pesoExamen*puntosListas);   
   printf("\n\nSi el programa funciona correctamente te dara \nla puntuacion obtenida al terminar la ejecucion");   
   printf("\n-----------------------------");
   
   printf("\nEl ejercicio se esta evaluando...");   
   printf("\n\nAlumnos de la asignatura 1: ");
   imprimirVector(nEle1, A1);
   printf("\n\nAlumnos de la asignatura 2: ");
   imprimirVector(nEle2, A2);   
   
   printf("\n\nComprobando lista resultado...\n\n");
   respuesta = ejercicio3(nEle1, nEle2, A1, A2, &LS);   
   if((respuesta != nSobresalientes))
   {
       printf("\n\tINCORRECTO: La funcion no devuelve el numero correcto de elementos de la lista. Devuelve %d en lugar de %d. Puntuacion obtenida en listas: %.3f puntos", respuesta, nSobresalientes, 0.0);                
   }
   else
   { 
       printf("\n\tNumero de elementos: %d\n\n", respuesta);
       comprobacion = comprobarLista(LS, Correctos, nSobresalientes);
       if(comprobacion == 1)
       {
          acumulada+=puntosListas;
          printf("\n\tCORRECTO: Puntuacion obtenida en listas: %.3f puntos", puntosListas);                           
       }
       else
       { 
           if(comprobacion == -1)           
              printf("\n\tINCORRECTO: La lista no contiene los elementos correctos. Puntuacion obtenida en listas: %.3f puntos", 0.0); 
           else        
              printf("\n\tINCORRECTO: El ultimo elemento de la lista no apunta a NULL. Puntuacion obtenida en listas: %.3f puntos", 0.0); 
       }       
   }                     

   printf("\n\n-----------------------------");
   printf("\nEJERCICIO 3: NOTA OBTENIDA");
   printf("\n\tEVALUACION EJERCICIO (sobre 10): %.3f puntos", acumulada);
   printf("\n\tTOTAL NOTA FINAL(sobre 3) : %.3f puntos", pesoExamen*acumulada);   
   printf("\n\tLa calificacion es PROVISIONAL y deber ser validada por la profesora");   
   printf("\n-----------------------------");   
   
   return 0;    
}


int imprimirVector(int nEle, struct datos * Vector)
{
  
  int i;
  printf("\n\n");
  for(i=0; i<nEle; i++)
  {
   printf("\t[%d, <%s>, %.2f]\n ",  Vector[i].codigo, Vector[i].nombre, Vector[i].nota);  
  }  
  return 1;   
}

int comprobarLista(struct lista* cabeza, struct datos* Correctos, int nEle)
{

   int* check = (int*) calloc (nEle, sizeof(int));
   
   struct lista * aux=cabeza;
   int i=0;
 
   printf("\n\t(%d, <%s>)->", aux->codigo, aux->nombre);     
   check[indice(Correctos, nEle, aux->codigo)]=1;  
   i++;
   aux=aux->sig;

   printf("\n\t(%d, <%s>)->", aux->codigo, aux->nombre);     
   check[indice(Correctos, nEle, aux->codigo)]=1;     
   i++;
   aux=aux->sig;
   
   printf("\n\t(%d, <%s>)->", aux->codigo, aux->nombre);     
   check[indice(Correctos, nEle, aux->codigo)]=1;     
   i++;
   aux=aux->sig;
    
   for(int i=0; i<nEle; i++)
   {
     if(check[i]!=1)
       return -1;
   }
   
   if(aux!=NULL)
     return -2;
   else
     printf("NULL\n"); 
   
   return 1;      
}

int indice(struct datos* V, int nEle, int codigo)
{
   int i;
   for(i=0; i<nEle; i++)
     if( V[i].codigo == codigo)
        return i;    
   return -1;
}
