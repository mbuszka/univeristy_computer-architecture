// signed
x < y == (((x ^ y) & x) | (x - y)) & (1 << N)

// unsigned
x < y == (((x ^ y) & y) | (x - y)) & (1 << N)
