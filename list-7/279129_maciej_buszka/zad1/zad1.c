#include <stdio.h>
#include <stdlib.h>

int clz(long);

int main(int argc, char *argv[]) {
  long num;
  sscanf(argv[1], "%ld", &num);
  int cnt = clz(num);
  printf("%d\n", cnt);
  return 0;
}
