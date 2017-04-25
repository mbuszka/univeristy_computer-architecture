all: zad2

lcm_gcd.o: lcm_gcd.s
	gcc -c -g lcm_gcd.s -o lcm_gcd.o

zad2.o: zad2.c
	gcc -c -g zad2.c -o zad2.o

zad2: zad2.o lcm_gcd.o
	gcc zad2.o lcm_gcd.o -o zad2

clean:
	rm *.o zad2
