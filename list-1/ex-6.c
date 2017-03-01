// a

s += b[j+1] + b[--j];

// Po transformacji

t1 = j + 1;
t2 = b + t1;
t3 = *t2;
t4 = j - 1;
t5 = b + t4;
t6 = *t5;
t7 = t3 + t6;
s = s + t7;

// b

a[i++] -= b * (c[j*2] + 1);

// Po transformacji

t1 = a + i;
t2 = *t1;
i = i + 1;
t3 = j * 2;
t4 = c + t3;
t5 = *t4;
t6 = t5 + 1;
t7 = b * t6;
t2 = t2 - t7;
*t1 = t2;
