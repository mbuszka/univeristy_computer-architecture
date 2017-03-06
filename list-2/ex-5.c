int32_t threefourths(int32_t x) {
  return (x >> 2) * 3 + (((x & 3) * 3) >> 2);
}
