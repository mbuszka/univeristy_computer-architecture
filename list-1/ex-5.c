struct A {
  int8_t  a;
  void   *b;
  int8_t  c;
  int16_t d;
};

struct A  us[];
struct A *vs;


void *usa = (void *) (((char *) us) + i * sizeof(struct A) + offsetof(struct A, a));
void *usc = (void *) (((char *) us) + j * sizeof(struct A) + offsetof(struct A, c));
void *vsd = (void *) (((char *) vs) + offsetof(struct A, d));
int16_t t = load_I8(usa) + loadI8(usc);
store_I16(vsd, t);
