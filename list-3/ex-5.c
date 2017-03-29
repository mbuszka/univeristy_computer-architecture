#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main() {
  int32_t x = (1 << 24) + 17;
  double  d = 1e-12;
  float   f = 1e5f;
  printf("1. True\n");
  printf("2. %s\n", x == (int32_t) (float) x ? "True" : "False");
  printf("3. %s\n", d == (double) (float) d ? "True" : "False");
  printf("4. True\n");
  printf("5. True\n");
  printf("6. %s\n", 1.0 / 2 == 1 / 2.0 ? "True" : "False");
  printf("7. %s\n", 1e1000 * 1e1000 >= 0 ? "True" : "False");
  printf("8. %s\n", (f + d) - f == d ? "False" : "True");
}
