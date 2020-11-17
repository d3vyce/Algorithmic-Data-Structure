all: princ

princ: princ.o bis.o nbre.o ecart.o
	gcc -o princ princ.o bis.o nbre.o ecart.o

princ.o: princ.c
	gcc -o princ.o -c princ.c -Wall 

bis.o: bis.c
	gcc -o bis.o -c bis.c -Wall 

nbre.o: nbre.c
	gcc -o nbre.o -c nbre.c -Wall

ecart.o: ecart.c
	gcc -o ecart.o -c ecart.c -Wall

clean: 
	rm *.o 