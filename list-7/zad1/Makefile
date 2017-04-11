all: zad1

clz.o: clz.s
	gcc -c -g clz.s -o clz.o

zad1.o: zad1.c
	gcc -c -g zad1.c -o zad1.o

zad1: zad1.o clz.o
	gcc zad1.o clz.o -o zad1

clean:
	rm *.o zad1
