long puzzle2(char *s, char *d) {
  char *current_letter = s;
  char *ptr = d;
  while (1) {
    do {
      if (*ptr == 0) return current_letter - s;
    while (*ptr++ != current_letter);
    current_letter++;
  }
}
