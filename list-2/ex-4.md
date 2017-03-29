 - Dla dodawania
```
z = ((x & 0x7F7F7F7F) + (y & 0x7F7F7F7F)) ^ ((x ^ y) & 0x80808080)
```

 - Dla odejmowania
```
z = ((x | 0x80808080) - (y & 0x7F7F7F7F)) ^ (~(y ^ x) & 0x80808080)
```
