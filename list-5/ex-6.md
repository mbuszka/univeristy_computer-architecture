`sizeof(union elem) = 16`
```
union elem* proc(union elem *e) {
  union elem* ret = e->e2.next;
  ret->e1.y -= *(ret->e1.p);
  e->e2.x = *(ret->e1.p);
  return ret;
}
