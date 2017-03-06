 - `(x > 0) || (x - 1 < 0)`
   To wyrażenie obliczy się do fałszu dla `x = INT_MIN`

 - `(x & 7) != 7 || (x << 29 < 0)`
   To wyrażenie jest zawsze prawdziwe, ponieważ jeżeli ostatnie 3 bity
   będą różne od 1, to pierwsza część alternatywy będzie fałszywa,
   w przeciwnym przypadku druga część będzie prawdziwa, bo liczba która
   powstanie poprzez przesunięcie będzie miała zapalony bit znaku.

 - `(x * x) >= 0`
   To wyrażenie jest fałszywe dla liczb x takich, że `2 ^ 31 <= x * x % 2 ^ 32`

 - `x < 0 || -x <= 0`
   To wyrażenie jest zawsze prawdziwe bo `abs(INT_MIN) > INT_MAX`

 - `x > 0 || -x >= 0`
   To wyrażenie jest fałszywe dla `INT_MIN`

 - `x + y == (uint32_t) y + (uint32_t) x`
   Prawda bo konwersje nie zmieniają wektora bitów

 - `x * ~y + (uint32_t) y * (uint32_t) x == -x`
   To wyrażenie jest fałszywe dla `y = INT_MIN`
