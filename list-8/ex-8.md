Musismy załadować 10^6 wierszy z pamięci
Przed każdym trzeba wykonać wybór wiersza, odczekać t_rcd, wybrać kolumnę,
odczekać t_cas i przesłać 1KiB danych

Mamy
`10^6 * (t_rcd + t_cas + 1024 / 16) / 800000000 = 10^6 * (20 + 64) / 800000000 = 84 / 800 = 100ms`

W trybie burst

`10^6 * (t_rcd + t_cas + 1024 / 64) / 8 * 10^(-10) = 1/200 = 5ms`
