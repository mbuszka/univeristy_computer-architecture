#include <stdio.h>
#include <stdlib.h>

unsigned long fibonacci(unsigned long n);

int main(int argc, char *argv[]) {
  unsigned long n;
  sscanf(argv[1], "%lu", &n);
  n = fibonacci(n);
  printf("%lu\n", n);
}
