    .global clz
    .type clz, "function"
    .text
clz:
    mov %rdi, %rcx
    sar $1, %rcx
    or  %rcx, %rdi
    mov %rdi, %rcx
    sar $2, %rcx
    or  %rcx, %rdi
    mov %rdi, %rcx
    sar $4, %rcx
    or  %rcx, %rdi
    mov %rdi, %rcx
    sar $8, %rcx
    or  %rcx, %rdi
    mov %rdi, %rcx
    sar $16, %rcx
    or  %rcx, %rdi
    mov %rdi, %rcx
    sar $32, %rcx
    or  %rcx, %rdi
    mov $0x5555555555555555, %rcx
    mov %rdi, %rax
    shr $1, %rax
    and %rcx, %rax
    and %rcx, %rdi
    add %rax, %rdi
    mov $0x3333333333333333, %rcx
    mov %rdi, %rax
    shr $2, %rax
    and %rcx, %rax
    and %rcx, %rdi
    add %rax, %rdi
    mov $0x0f0f0f0f0f0f0f0f, %rcx
    mov %rdi, %rax
    shr $4, %rax
    and %rcx, %rax
    and %rcx, %rdi
    add %rax, %rdi
    mov $0x00ff00ff00ff00ff, %rcx
    mov %rdi, %rax
    shr $8, %rax
    and %rcx, %rax
    and %rcx, %rdi
    add %rax, %rdi
    mov $0x0000ffff0000ffff, %rcx
    mov %rdi, %rax
    shr $16, %rax
    and %rcx, %rax
    and %rcx, %rdi
    add %rax, %rdi
    mov $0x00000000ffffffff, %rcx
    mov %rdi, %rax
    shr $32, %rax
    and %rcx, %rax
    and %rcx, %rdi
    add %rax, %rdi
    mov $64, %rax
    sub %rdi, %rax
    ret

.size clz, . - clz
;     l = %r8
;     r = %r9
;     mov $64, l
;     mov $0,  r
; beg:
;     mov l, %rcx
;     add r, %rcx
;     shr %rcx
;     mov $1, %rsi
;     shl %cl, %rsi
;     cmp %rsi, %rdi
;     jb bel
;     ja abv
;     jmp fin
; bel:
;     cmp r, %rcx
;     je fin
;     mov %rcx, l
;     jmp beg
; abv:
;     mov %rcx, r
;     jmp beg
; fin:
;     mov $64, %rax
;     sub %rcx, %rax
;     ret
