#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t div3(int32_t n) {
  if (n >= 0) {
    int64_t t = n;
    t *= 0x55555556;
    return t >> 32;
  } else {
    int64_t t = n;
    t *= 0x55555556;
    return (t >> 32) + 1;
  }
}

void test() {
  int n = 1000;
  for (int i=-n; i<=n; i++) {
    if (i/3 != div3(i)) printf("FAIL: %d\n", i);
  }
}

int main() {
  int32_t n = INT32_MIN;
//  printf("%lx\n", 0x100000000 / 3);
//  printf("%d/3 =? %d\n", n, div3(n));
  test();
  return 0;
}
