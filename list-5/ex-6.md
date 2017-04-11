`sizeof(union elem) = 16`
```
union elem* proc(union elem *e) {
  union elem* ret = e->e2.next;
  e->e2.x = *(ret->e1.p) - ret->e1.y;
  return ret;
}
