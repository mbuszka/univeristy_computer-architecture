    .global fibonacci
    .type fibonacci, "function"
    .text
fibonacci:
    push %rbp
    mov  %rsp, %rbp
    cmp  $2, %rdi
    jle  base
    dec  %rdi
    push %rdi
    sub  $8, %rsp
    call fibonacci
    add  $8, %rsp
    pop  %rdi
    push %rax
    dec  %rdi
    sub  $8, %rsp
    call fibonacci
    add  $8, %rsp
    pop  %rdi
    add  %rdi, %rax
    pop  %rbp
    ret
base:
    mov $1, %rax
    pop %rbp
    ret
    .size fibonacci, . - fibonacci
