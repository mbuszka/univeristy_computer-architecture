    .global _start
    .type _start, "function"
    .text

_start:
    mov $0, %rax # read
    mov $0, %rdi
    mov $buf, %rsi
    mov $1, %rdx
    syscall
    cmp $0, %rax
    je fin
    mov $32,%rdi
    movzx (%rsi), %rax
    cmp $97, %rax
    jl lt
    sub %rdi, (%rsi)
    jmp cont
lt:
    add %rdi, (%rsi)

cont:
    mov $1, %rax # write
    mov $1, %rdi
    mov $buf, %rsi
    mov $1, %rdx
    syscall

    jmp _start
fin:
    # exit(0)
    mov $60, %rax # exit
    xor %rdi, %rdi
    syscall
    .size _start, . - _start

    .bss
buf:
    .space 1
