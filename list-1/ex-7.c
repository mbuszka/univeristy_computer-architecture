#include <stdio.h>
// Original

void insertion_sort_1(int arr[], int length) {
  int j, temp;
  for (int i=0; i < length; i++) {
    j = i;
    while (j > 0 && arr[j] < arr[j-1]) {
      temp = arr[j];
      arr[j] = arr[j-1];
      arr[j-1] = temp;
      j--;
    }
  }
}

// Po pierwszej transformacji

void insertion_sort_2(int arr[], int length) {
  int j, temp;
  {
    int i = 0;
    while (i < length) {
      j = i;
inner :
      if (j>0 && arr[j] < arr[j-1]) {
        temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
        j--;
        goto inner;
      }
      i++;
    }
  }
}

void insertion_sort_3(int arr[], int length) {
  int j, temp;
  {
    int i = 0;
    outer: if (i < length) {
      j = i;
      inner: if (j>0 && arr[j] < arr[j-1]) {
        temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
        j--;
        goto inner;
      }
      i++;
      goto outer;
    }
  }
}

void insertion_sort(int arr[], int length) {
  int j, temp;
  {
    int i = 0;
    int b; 
outer: 
    b = i < length;
    if (b) goto outer_body;
    goto outer_end;
outer_body: 
    j = i;
inner:
    b = j > 0 && arr[j] < arr[j-1];
    if (b) goto inner_body;
    goto inner_end;
inner_body:
    temp = arr[j];
    arr[j] = arr[j-1];
    arr[j-1] = temp;
    j--;
    goto inner;
inner_end:
    i++;
    goto outer;
outer_end: ;
  }
}

int main() {
  int arr[] = {6, 5,1,23, 56}; 
  insertion_sort(arr, 5);
  printf("%d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
  return 0;
}
