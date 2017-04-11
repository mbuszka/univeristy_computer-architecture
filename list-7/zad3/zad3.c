#include <stdio.h>
#include <stdlib.h>

void insert_sort(long *, long *);

int main(int argc, char *argv[]) {
  int n = argc - 1;
  long arr[n];
  for (int i=0; i<n; i++) {
    sscanf(argv[i+1], "%ld", &arr[i]);
  }
  insert_sort(&arr[0], &arr[n-1]);

  printf("[ ");
  for (int i=0; i<n; i++) {
    printf("%ld ", arr[i]);
  }
  printf("]\n");
}
