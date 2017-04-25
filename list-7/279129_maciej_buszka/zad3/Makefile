all: zad3

insert_sort.o: insert_sort.s
	gcc -c -g insert_sort.s -o insert_sort.o

zad3.o: zad3.c
	gcc -c -g zad3.c -o zad3.o

zad3: zad3.o insert_sort.o
	gcc zad3.o insert_sort.o -o zad3

clean:
	rm *.o zad3
