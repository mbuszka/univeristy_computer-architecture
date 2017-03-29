uint32_t abs(int32_t x) {
  (((x >> 31)) & (-x)) + (~(x >> 31) & x);
}
