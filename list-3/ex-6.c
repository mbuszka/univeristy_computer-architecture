#include <stdio.h>
#include <stdint.h>
#include <string.h>

float mypow(float f, int32_t i) {
  int32_t x;
  int32_t e;
  int32_t m;
  int32_t s;
  //memcpy((&x)+3, &f,   1);
  //memcpy((&x)+2, (&f)+1, 1);
  //memcpy((&x)+1, (&f)+2, 1);
  memcpy(&x,   (&f), 4);
  m = x & 0x007FFFFF;
  e = (x & 0x7F800000) >> 23;
  s = ((x & 0x80000000) >> 31) & 1;
  printf("%x\n", m);
  printf("%d\n", e);
  if (e == 0 && m == 0) {
    printf("a\n");
    return f; 
  }
  if (e == 0xFF) {
    printf("b\n");
    return f;
  }
  if (e == 0) {
    printf("c\n");
    while (!(m & 0x00400000)) {
      m <<= 1;
      e --;
    }
  }
  printf("dupa\n");
  e += i;  
  if (e > 0xFF) {
    x = (s << 31) | 0x7F800000;
    goto end;
  }
  if (e <= 0 && e > -24) { 
    x = (s << 31) | (m >> (-e));
    goto end;
  }
  if (e <= -24) {
    x = s << 31;
    goto end;
  }
  x = (s << 31) | (e << 23) | m;
end:
  memcpy(&f, &x, 4);
  return f;
}

int main() {
  printf("%f\n", mypow(1.5, -1));
}
