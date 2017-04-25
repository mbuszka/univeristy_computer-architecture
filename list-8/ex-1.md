1. Wyłączenie przerwań może być dozwolone jedynie w trybie uprzywilejowanym
   jako, że po takiej akcji nie można wywłaszczyć procesu.

2. Odczytanie zegara czasu rzeczywistego nie wymaga trybu uprzywilejowanego.

3. Ustawienie rozdzielczości ekranu również nie wymaga trybu uprzywilejowanego.

4. Uśpienie procesora wymaga trybu uprzywilejowanego, ponieważ gdyby jakiś
   proces wykonał taką instrukcję bez uprzedniego ustawienia przerwania/timera
   mógłby doprowadzić do zatrzymania całego systemu.
