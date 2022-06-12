inicio:crear_ejecutable
crear_ejecutable: main.o funciones.o
	gcc main.o funciones.o -o ejercicio
main.o: main.c 
	gcc -c main.c 
funciones.o:funciones.c
	gcc -c funciones.c
clean:
	rm *.o