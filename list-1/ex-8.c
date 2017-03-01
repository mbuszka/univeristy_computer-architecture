#include <stdio.h>
#include <stdint.h>

void secret(uint8_t *to, uint8_t *from, size_t count) {
  static const void *labels[] = { &&c0, &&c1, &&c2, &&c3, &&c4, &&c5, &&c6, &&c7 };
  size_t n = (count + 7) / 8;
  size_t m = count % 8;
  int b;
  goto *labels[m];
c0: *to++ = *from++;
c7: *to++ = *from++;
c6: *to++ = *from++;
c5: *to++ = *from++;
c4: *to++ = *from++;
c3: *to++ = *from++;
c2: *to++ = *from++;
c1: *to++ = *from++;
  b = --n > 0;
  if (b) goto c0;
}

int main() {
  char src[12] = "Hello World";
  char dst[12];
  secret(dst, src, 12);
  printf("%s\n", dst);
}
