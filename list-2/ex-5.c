int32_t threefourths(int32_t x) {
  return (x >> 2) + (x >> 1) + ((x & 3) == 3); 
}
