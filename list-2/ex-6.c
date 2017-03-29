// signed i unsigned tak samo
x < y == {
  ((x^y) & x | (~((x^y) >> (N-1)) & (x - y))) & (1 << (N-1))
}


// unsigned
// x < y == (((x ^ y) & y) | (x - y)) & (1 << N)
