#include <stdio.h>
#include "funciones.h"

int imprimirVector(int nEle, int* Vector);

int main()
{
   int nEle = 5, resultado1, resultado2;
   char opcion;   
   
   float acumulada = 0;
   float pesoExamen=0.3;
   float puntosRecursividad=2.5;   
  
   int Vector1[]={-4,-7,-1,-9,-3};
   int Vector2[]={2,8,15,6,5};
   int Vector3[]={5,6,15,8,2};
 
   printf("\n\n-----------------------------");
   printf("\nPUNTUACION DEL EJERCICIO 2: RECURSIVIDAD");
   printf("\n\tTOTAL EJERCICIO (sobre 10): %.3f puntos", puntosRecursividad);
   printf("\n\tTOTAL NOTA FINAL(sobre 3) : %.3f puntos", pesoExamen*puntosRecursividad);   
   printf("\n\nSi el programa funciona correctamente te dara \nla puntuacion obtenida al terminar la ejecucion");
   printf("\n-----------------------------");
   
   printf("\n\nEl ejercicio se esta evaluando...");    
   printf("\n\nVector 1: ");
   imprimirVector(nEle, Vector1);
   printf("\n\nVector 2: ");
   imprimirVector(nEle, Vector2);   
   printf("\n\nVector 3: ");
   imprimirVector(nEle, Vector3);

   printf("\nComprobando si Vector 2 es el inverso de Vector 1...");   
   resultado1 = ejercicio2(nEle, Vector1, Vector2); 
   printf("\n\tValor esperado: 0");
   printf("\n\tValor devuelto por tu funcion recursiva: %d", resultado1);
   
   printf("\n\nComprobando si Vector 2 es el inverso de Vector 3...");   
   resultado2 = ejercicio2(nEle, Vector2, Vector3); 
   printf("\n\tValor esperado: 1");   
   printf("\n\tValor devuelto por tu funcion recursiva: %d", resultado2);      
 
   if((resultado1!=0) || (resultado2!=1))
   {
       printf("\n\n\tINCORRECTO: puntuacion obtenida en recursividad: %.3f puntos", 0.0);
   }
   else
   {   
       printf("\n\nPREGUNTA: La funcion programada es recursiva?");   
       printf("\n\tRESPUESTA (S|N): ");
       scanf("%c", &opcion);
       getchar();
       if((opcion=='S')||(opcion=='s')) 
       {
          acumulada+=puntosRecursividad;
          printf("\n\tCORRECTO: Puntuacion obtenida en recursividad: %.1f puntos", puntosRecursividad);               
       }
       else
         printf("\n\n\tINCORRECTO: puntuacion obtenida en recursividad: %.3f puntos", 0.0);
   }    

   printf("\n\n-----------------------------");
   printf("\nEJERCICIO 2: NOTA OBTENIDA");
   printf("\n\tEVALUACION EJERCICIO (sobre 10): %.3f puntos", acumulada);
   printf("\n\tTOTAL NOTA FINAL (sobre 3) : %.3f puntos", pesoExamen*acumulada);   
   printf("\n\tLa calificacion es PROVISIONAL y deber ser validada por la profesora");   
   printf("\n-----------------------------");   
   
   return 0;    
}



int imprimirVector(int nEle, int * Vector)
{
  
  int i;
  printf("\n\t(");
  for(i=0; i<nEle-1; i++)
  {
        printf(" %d,", Vector[i]);
  }
  printf(" %d)\n", Vector[i]);  
  
 return 1;
   
}



