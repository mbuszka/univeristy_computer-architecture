# Exercise 2
### Before memory accesses
| Page table  ||     | | TLB    | | | |
| ----|-------|----  |-| ---    |-|-|-|
| VPN | Valid?| PPN  | | Valid? | Tag | LRU | PPN
| 0   | 1     | 5    | | 1      | 11  | 0   | 12
| 1   | 0     | disk | | 1      | 7   | 1   | 4
| 2   | 0     | disk | | 1      | 3   | 2   | 6
| 3   | 1     | 6    | | 0      | 4   | 3   | 9
| 4   | 1     | 9    | |
| 5   | 1     | 11   | |
| 6   | 0     | disk | |
| 7   | 1     | 4    | |
| 8   | 0     | disk | |
| 9   | 0     | disk | |
| 10  | 1     | 3    | |
| 11  | 1     | 12   | |
| 12  | 0     | none | |

### Memory accesses
 | Address | VPN | TLB hit? | Page fault? | PPN |
 | ------- | --- | -------- | ----------- | --- |
 | 4669    | 1   | no       | yes         | 13  |
 | 2227    | 0   | no       | no          | 5   |
 | 13916   | 3   | yes      | no          | 6   |
 | 34587   | 8   | no       | yes         | 14  |
 | 48870   | 11  | no       | no          | 12  |
 | 12608   | 3   | yes      | no          | 6   |
 | 49225   | 12  | no       | yes         | 15  |
 
### After memory accesses
| Page table  ||     | | TLB    | | | |
| ----|-------|----  |-| ---    |-|-|-|
| VPN | Valid?| PPN  | | Valid? | Tag | LRU | PPN
| 0   | 1     | 5    | | 1      | 11  | 1   | 12
| 1   | 0     | 13   | | 1      | 12  | 3   | 15
| 2   | 0     | disk | | 1      | 3   | 2   | 6
| 3   | 1     | 6    | | 1      | 8   | 0   | 14
| 4   | 1     | 9    | |
| 5   | 1     | 11   | |
| 6   | 0     | disk | |
| 7   | 1     | 4    | |
| 8   | 1     | 14   | |
| 9   | 0     | disk | |
| 10  | 1     | 3    | |
| 11  | 1     | 12   | |
| 12  | 1     | 15   | |

# Exercise 3
 - *Pagefault* - exception raised by MMU when address being accessed has no entry in page table
   - *major* - when requested page **isn't** in memory
   - *minor* - when requested page **is** in memor

#### Size of pages shouldn't be too small
- The smaller the pages, more of them are needed to cover the address space, which leads to:
  - Increased page table size
  - More page faults and less efficient TLB 

#### But they shouldn't be too big either
 - Internal fragmentation
 - Bloated working set

# Exercise 4
 - 32-bit addresses
 - 4KiB pages
 - 1GiB used address space
 
 1. Single level page table
    - `4MiB`
 2. Two level page table
    - optimistic `1028KiB`
    - pesimistic `4100KiB`

# Exercise 5
When switching address spaces, the TLB should be flushed as two different processes may use the same virtual address.
One may circumvent this by adding an extra tag to each TLB entry, unique for every address space.

# Exercise 6
 - pesimistic `4*4KiB = 16KiB`
 - opimistic `64*4KiB = 256KiB`
 - for huge pages swap `KiB` for `MiB`

# Exercise 7
Strona (page) to kawałek wirtualnej przestrzeni adresowej długości 2k. Cała przestrzeń adresowa jest podzielona na strony. Ramka (frame) to fragment pamięci fizycznej wielkości strony.

##### Deskryptor katalogu stron (page directory entry) taka struktura, długości 32 bitów

![](http://wiki.osdev.org/images/9/94/Page_dir.png)

ADRES jest adresem fizycznym !
- Avail. - bity do użytku przez system operacyjny
- S - jeżeli jest zapalony, to wskaźnik jest na stronę wielkości 4MB, wtedy adres musi być wyrównany do 4MB, a bity od 12 do 21 są zarezerwowane
- A - zapalony, jeżeli strona była użyta (odczyt/zapis) nie jest czyszczona przez CPU
- D - jeżeli zapalony, to nie będzie cache’owana
- W - jeżeli zapalony, to cache będzie write-through, w przeciwnym przypadku cache będzie write-back
- U - jeżeli zapalony, to strona będzie dostępna dla wszystkich, jak nie to tylko dla nadzorcy
- R - zapalony - read/write, jak nie, to read only
- P - czy jest w pamięci fizycznej

##### Deskryptor strony (page table entry) tak jak poprzednio, też 32 bity, poniżej opisane są tylko różniące się bity

![](http://wiki.osdev.org/images/9/9b/Page_table.png)

- G - global, jeżeli ustawiony, to TLB nie będzie odświeżał tego adresu
- D - dirty, jeżeli ustawiony, to nastąpił zapis do tej strony
- C - tak jak D w deskryptorze katalogu


##### Używanie pamięci podręcznej:
- D/C cache disable
- W Write-back vs write-though 
##### Wspomagają algorytmy
 - A czy była używana
 - D dirty flag
##### Uprawnienia dostępu
 - U User vs Superuser
 - Read/Write

# Exercise 8

 - *homonym* - same virtual address but mapped onto differnet physical
 - *synonym* - same physical address but mapped onto different virtual

The homonym problem can be solved by using physical address for tag, or by storing address space id, \
but the synonyms can only be circumvented by flushng cache or by using disjoint address spaces
