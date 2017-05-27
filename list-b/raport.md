# Procesor
 - Core i7-3520M
 - L1 32M - 8-way
 - L2 256M - 8-way
 - L3 6144M - 12-way

# Zadanie 1
Czas działania dla:
 - `./transpose -n 15 -v 0` ok 12.1 sekundy
 - `./transpose -n 15 -v 1` ok 2.5 sekundy

# Zadanie 2
Czas działania dla:
 - `./randwalk -n 7 -s 16 -v 0` ok 7.8 sekundy
 - `./randwalk -n 7 -s 16 -v 1` ok 3.9 sekundy

# Zadanie 3
Czas działania dla:
 - `./bsearch -n 23 -t 24 -v 0` ok 9.3 sekundy
 - `./bsearch -n 23 -t 24 -v 1` ok 3.4 sekundy

# Zadanie 4
Każda permutacja ma jeden parametr `d`, przekazywany z linii poleceń. Do programu dodana jest flaga `-p` której argumentem jest `<podpunkt><log(d)>`. Dla przykładu `./cache -n 22 -s 23 -t 100 -p a3` oznacza, że chcemy permutację do podpunktu a, z paramatrem `d == 2 ^ 3`
 - a) Permutacja polega na cyklicznym odczytywaniu elementów o indeksach `0, d, 2d, ...`
    Dla parametrów `n == 22, `s == 23`, `t == 100` otrzymałem następujące wyniki
    
    | wartość `log(d)` | czas [s]  |
    | -----------      | --------- |
    | 0                | 2.30      |
    | 1                | 2.36      |
    | 2                | 2.44      |
    | 3                | 2.69      |
    | 4                | 5.06      |
    | 5                | 11.4      |
    | 6                | 23.1      |
    | 10               | 60        |

    Można zaobserwować, że pierwszy istotny wzrost czasu nastąpił dla `d = 16`, stąd wnioskuję, że linia cache'u ma `16  * sizeof(int)`, czyli 64 bajty długości. Wydłużenie czasu dla `d = 32` wynika z faktu, że ten model procesora ładuje po dwie linie cache'u na raz. Kolejne spowolnienia wynikają według mnie z nietrafiania w TLB.

 - b) Permutacja polega na cyklicznym przeglądaniu co 16 elementu. Maksymalna wielkość tablicy dla której czas pozostaje względnie stały będzie odpowiadała wielkości poziomu cache.
    Dla wywołania `./cache -n log(n) -s 20 -t 1000 -p b0` tablica będzie wielkości n
    Natomiast dla wywołania `./cache log(n) -s 20 -t 1000 -p b<log(k)>` tablica będzie wielkości `n / 2 + k`

    | wielkość tablicy | czas [s] |
    | ---------------- | -------- |
    | 4K               | 2.84     |
    | 16K              | 2.83     |
    | 32K              | 2.90     |
    | 64K              | 4.81     |
    | 128K             | 4.84     |
    | 256K             | 4.91     |
    | 512K             | 5.31     |
    | 1024K            | 5.30     |
    | 4096K            | 5.34     |
    | 6144K            | 5.35     |
    | 8192K            | 6.27     |
    | 16M              | 6.30     |

    Widać, że cache L1 ma rozmiar 32K, L2 ma rozmiar 256K, natomiast L3 6144K

 - c) Permutacja polega na cyklicznym przeglądaniu elemtu o indeksie podzielnym przez wielkość L1

    Badając iloraz `k = n / L1` poznamy rozmiar zbioru L1, wywołanie `./cache -n log(n) -s 20 -t 1000 -p c13`
    | k     | czas [s] |
    | ----- | -------- |
    | 1     | 2.81     |
    | 2     | 2.83     |
    | 4     | 2.82     |
    | 8     | 2.84     |
    | 16    | 7.64     |
      
    Tak więc L1 ma zbiory 8 elementowe



