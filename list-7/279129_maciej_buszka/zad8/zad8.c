#include <stdlib.h>
#include <stdio.h>

double approx_sqrt(double x, double eps);

int main(int argc, char *argv[]) {
  double v, eps, r;
  sscanf(argv[1], "%lf", &v);
  sscanf(argv[2], "%lf", &eps);
  r = approx_sqrt(v, eps);
  printf("val : %lf, eps : %lf, sqrt : %lf\n", v, eps, r);
  return 0;
}
