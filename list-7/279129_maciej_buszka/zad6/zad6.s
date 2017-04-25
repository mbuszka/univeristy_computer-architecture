    .global main
    .type main, "function"
    .text
main:
    push %rbp
    mov  %rsp, %rbp
    push %r12
    push %r13
    push %r14
    push %rbx
    argc = %rdi
    argv = %r12
    arr  = %r13
    arr_size = %rdx
    min = %rbx
    max = %r14
    mov %rsi, argv
    lea  -1(argc), arr_size
    lea (,arr_size,8), %rax
    sub %rax, %rsp
    mov %rsp, arr
    push argc
    push arr_size

    sub $8, %rsp
    mov arr_size, %rcx
body:
      push %rcx
      mov (argv, %rcx, 8), %rdi
      call atol
      pop %rcx
      mov %rax, -8(arr, %rcx, 8)
      cmp min, %rax
      cmovl %rax, min
      cmp max, %rax
      cmovg %rax, max
    loop body
    add $8, %rsp

    mov  $format, %rdi
    mov  min, %rsi
    mov  max, %rdx
    mov  $0, %rax
    call printf
    pop  arr_size
    pop  argc
    lea  (%rsp,arr_size,8), %rsp
    pop  %rbx
    pop  %r14
    pop  %r13
    pop  %r12
    pop  %rbp
    ret
    .size main, . - main

    .section .rodata
format:
    .asciz "min: %ld, max %ld\n"
