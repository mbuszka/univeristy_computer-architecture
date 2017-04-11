    .global insert_sort
    .type insert_sort, "function"
    .text
insert_sort:
    fst = %rdi
    lst = %rsi
    ptr = %rax
    swp = %rdx
    tmp = %r8
    tmp_ptr = %rcx
    lea 8(fst), ptr
outer:
    cmp lst, ptr
    ja fin
    lea -8(ptr), tmp_ptr
    mov (ptr), swp
inner:
      cmp tmp_ptr, fst
      ja  inner_end
      mov (tmp_ptr), tmp
      cmp tmp, swp
      ja  inner_end
      mov tmp, 8(tmp_ptr)
      sub $8, tmp_ptr
      jmp inner
inner_end:
    mov swp, 8(tmp_ptr)
    add $8, ptr
    jmp outer
fin:
    ret
    .size insert_sort, . - insert_sort
