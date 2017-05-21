Wersję permutacji należy wybrać zmieniając stałą `VERSION` na odpowiednio
`'a'`, `'b'`, `'c'` w kodzie źródłowym `cache.c`

 - a) Dla permutacji która wybiera pierwszy i a-ty element z danego bloku tablicy
      co `2^6` elementów, jeżeli a będzie większe niż `cache_size / sizeof(int)` to
      zaobserwujemy nagły wzrost czasu wykonania. Na moim komputerze `a == 15`
 
 - b) Dla permutacji która wybiera pierwszy element z każdej linii cache'u i
      przebiega w koło tablicy, możemy zbadać wielkość cache'u kolejnych poziomów
      dobierając odpowiednio rozmiar tablicy
