``` 
struct A {
  int8_t  a;
  void   *b;
  int8_t  c;
  int16_t d;
};
    
struct B {
  uint16_t a;
  double   b;
  void    *c;
};
```

Rozmiary :
 - `sizeof(A) == 12`
 - `sizeof(B) == 24`

Przesunięcia :
  
```
   offsetof(A, a) == 0;
   offsetof(A, b) == 4;
   offsetof(A, c) == 8;
   offsetof(A, d) == 10;
```
```
   offsetof(B, a) == 0;
   offsetof(B, b) == 8;
   offsetof(B, c) == 16;
```

Reorganizacja :
```
struct A {
  void   *b;
  int16_t d;
  int8_t  a;
  int8_t  c;
};

sizeof(struct A) == 8;
```

```
struct B {
  double   b;
  void    *c;
  uint16_t a;
};

sizeof(struct B) == 16;
```

Takie zachowanie wynika z konieczności ułożenia danych tak, aby były poprawnie dopasowane, tzn ich adres powinien być wielokrotnością ich rozmiaru. Wielkość struktury musi być wielokrotnością rozmiaru największej składowej.
