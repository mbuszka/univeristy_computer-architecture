all : ex-1.o ex-3.o ex-7.o

ex-1.o : ex-1.c
	gcc -c -o ex-1.o ex-1.c

ex-3.o : ex-3.c
	gcc -c -o ex-3.o -Og ex-3.c

ex-7.o : ex-7.c
	gcc -c -o ex-7.o -Og -fpic ex-7.c

clean:
	rm -f *.o
