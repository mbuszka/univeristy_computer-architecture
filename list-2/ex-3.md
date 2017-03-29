`(x & y) | (~(x | y) & (1 << (N - 1))
 == ~(x ^ y) & (1 << (N - 1))`

A może tak:

`~(x ^ y) & (x ^ (x + y)) & (1 << (N - 1))`
Sprawdzamy czy są tego samego znaku, jeżeli są, to sprawdzamy czy wynik się przekręcił

