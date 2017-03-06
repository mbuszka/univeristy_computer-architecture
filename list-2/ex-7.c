uint32_t abs(int32_t x) {
  int b = (x & (1 << 31));
  b * (0 - x) + ~b * x;
}
