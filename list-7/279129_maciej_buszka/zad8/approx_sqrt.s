    .global approx_sqrt
    .type approx_sqrt, "function"
    .text
approx_sqrt:
    v     = %xmm0
    eps   = %xmm1
    x     = %xmm2
    delta = %xmm3
    z     = %xmm4
    tmp   = %xmm5
    t     = %xmm6
    movsd zero, z
    movsd one, x
next:
    movsd   v, delta
    divsd   x, delta
    addsd   x, delta
    mulsd   halve, delta
    movsd   delta, t
    subsd   x, t
    movsd   z, tmp
    subsd   t, tmp
    maxsd   t, tmp
    comisd  eps, tmp
    jbe fin
    movsd delta, x
    jmp next
fin:
    movsd x, %xmm0
    ret
    .size approx_sqrt, . - approx_sqrt

    .section .rodata
halve : .double 0.5
one   : .double 1
zero  : .double 0
