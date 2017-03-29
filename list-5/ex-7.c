long switch_prob(long x, long n) {
  switch (n) {
    case 60:
    case 61: return 8 * x;
    case 64: return x / 8;
    case 62: x *= 15;
    case 65: x *= x;
    case 63: return x + 75;
}
