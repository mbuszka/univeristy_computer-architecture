int puzzle(long x, unsigned n) {
  if (n == 0) return 0;
  int d = 0;
  int a = 0;
  do {
    a += x & 1;
    x >>= 1;
    d ++;
  } while (d != n);
   return a;
}

int puzzle(long x, unsigned n) {
  int cnt = 0;
  for (unsigned i=0; i != n; i++) {
    cnt += x & 1;
    x >>= 1;
  }
  return cnt;
}
