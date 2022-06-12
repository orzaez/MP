inicio: saluda crear_ejecutable

saluda:
	@echo "Esto es el makefile de Ángel"

crear_ejecutable: main.o funciones.o
	gcc main.o funciones.o -o ejecutable

main.o: main.c
	gcc -c main.c

funciones.o: funciones.o
	gcc -c funciones.c
clean:
	rm *.o