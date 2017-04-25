    .global lcm_gcd
    .text
    .type lcm_gcd, "function"
lcm_gcd:
    mov %rdi, %rax
    mov %rsi, %r8
beg:
    cmp %rdi, %rsi
    je fin
    jl lesser
    sub %rdi, %rsi
    jmp beg
lesser:
    sub %rsi, %rdi
    jmp beg
fin:
    xor %rdx, %rdx
    div %rdi
    mul %r8
    mov %rdi, %rdx
    ret
.size lcm_gcd, . - lcm_gcd
