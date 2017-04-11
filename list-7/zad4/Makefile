all: zad4

fibonacci.o: fibonacci.s
	gcc -c -g fibonacci.s -o fibonacci.o

zad4.o: zad4.c
	gcc -c -g zad4.c -o zad4.o

zad4: zad4.o fibonacci.o
	gcc zad4.o fibonacci.o -o zad4

clean:
	rm *.o zad4
