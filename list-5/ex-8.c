typedef struct A {
  long u[2];
  long *v;
} SA;

typedef struct B {
  long p[2];
  long q;
} SB;

SB eval(SA s) {
  return {{ s.u[1] * *s.v,
            s.u[0] - *s.v },
	  s.u[0] - s.u[1]};
}

long wrap(long x, long y, long z) {
  SA a = {{x, y}, &z}
  SB b = eval(a);
  return (b.p[1] + b.p[0]) * b.q;
}
