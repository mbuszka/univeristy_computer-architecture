uint32_t x;
uint32_t i, k;

int b = (((1 << i) & x) >> i) << k;
x = x & ~b | b;
