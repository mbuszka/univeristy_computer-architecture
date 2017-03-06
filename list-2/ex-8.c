int sign(int x) {
  return 1 - (x == 0) - (x & (1 << (N - 1))); 
}
