Słowo kluczowe `volatile` sprawia, że zmienna która została z nim zadeklarowana zostanie zawsze odcztana z pamięci, ponieważ jej wartość może się zmienić pomiędzy dostępami. Powstrzymuje to niektóre optymalizacje, mogące bez niego powodować nieprawidłowe działanie programu.

Używane jest gdy zmienna którą deklarujemy jest:
 - rejestrem bądź interfejsem sprzętowym zmapowanym na pamięć
 - zmienną globalną modyfikowaną przez procedurę obsługi przerwania
 - zmienną globalną modyfikowaną przez wiele wątków (aczkolwiek nie jest to polecane)

