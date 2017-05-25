/*
 * Template for cache organization exploring assignment.
 *
 * $ ./cache -n 26 -s 26 -t 20
 * Time elapsed: 2.322265 seconds.
 */

#include "common.h"

#define DEBUG 0
#define VERSION 'c'
#define L1 (1 << 13)
#define L2 (1 << 16)


/* Do not touch this procedure! */
int array_walk(volatile int *array, int steps) {
  int sum = 0, i = 0;

  do {
    if (i < 0)
      break;
#if DEBUG
    printf("%d -> %d\n", i, array[i]);
#endif
    i = array[i];
    sum += i;
  } while (--steps);

  return sum;
}

/* XXX: You are only allowed to change this procedure! */
void generate_permutation(int *array, int size, int perm) {
  /* Walk over every even element, then over every odd. */
  //for (int i = 0; i < size - 1; i += 2) {
  //  array[i] = i + 2;
  //  array[i + 1] = i + 3;
  //}

  /* Link the end of even list to the beginning of odd list. */
  //array[size - 2] = 1;

  /* Finish the sequence, note it's not circular! */
  //array[size - 1] = -1;
  
  int s = 64;
  int a = 18;
  int b = L1;
  switch (perm) {
    case 'a':
      array[0] = a;
      if (size < a) {
        array[0] = 0;
	break;
      }
      array[a] = 0;
      for (int i=s; i < size - a; i += s) {
        array[i - s + a] = i;
        array[i] = i + a;
        array[i + a] = 0;
      }
      break;
    case 'b':
      array[0] = 0;
      for (int i=16; i < size; i += 16) {
        array[i-16] = i;
        array[i] = 0;
      }
      break;
    case 'c':
      array[0] = 0;
      for (int i=b; i < size; i += b) {
        array[i-b] = i;
        array[i] = 0;
      }
      break;
  }
}

int main(int argc, char **argv) {
  int opt, size = -1, steps = -1, times = -1, perm = -1;
  bool error = false;

  while ((opt = getopt(argc, argv, "n:s:t:p:")) != -1) {
    if (opt == 'n') 
      size = 1 << atoi(optarg);
    else if (opt == 's')
      steps = 1 << atoi(optarg);
    else if (opt == 't')
      times = atoi(optarg);
    else if (opt == 'p')
      perm = optarg[0] >= 'a' && optarg[0] <= 'c' ? optarg[0] : -1;
    else
      error = true;
  }

  if (error || size < 0 || steps < 0 || times < 0 || perm < 0) {
    printf("Usage: %s -n log2(size) -s log2(steps) -t times -p perm\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  int *array = NULL;

  if (posix_memalign((void **)&array, getpagesize(), size * sizeof(int)) != 0)
    fail("Failed to allocate memory!");

  printf("Generate array of %d elements (%ld KiB)\n", size, size * sizeof(int) >> 10);
  generate_permutation(array, size, perm);
  flush_cache();

  printf("Perfom walk %d times with %d steps each.\n", times, steps);

  _timer_t t;
  timer_reset(&t);
  for (int i = 0; i < times; i++) {
    timer_start(&t);
    array_walk(array, steps);
    timer_stop(&t);
  }
  timer_print(&t);

  free(array);

  return EXIT_SUCCESS;
}
