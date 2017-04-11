#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned long lcm, gcd;
} result_t;

result_t lcm_gcd(unsigned long, unsigned long);

int main(int argc, char *argv[]) {
  unsigned long a, b;
  sscanf(argv[1], "%lu", &a);
  sscanf(argv[2], "%lu", &b);
  result_t res = lcm_gcd(a, b);
  printf("lcm: %lu, gcd: %lu\n", res.lcm, res.gcd);
  return 0;
}
