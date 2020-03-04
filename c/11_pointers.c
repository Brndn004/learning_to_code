#include <stdio.h>

int main() {
  int n = 10;

  /* your code goes here */
  int * pointer_to_n = &n;

  *pointer_to_n += 1;
  printf("printf(n): %d\nprintf(pointer_to_n): %p\nprintf(*pointer_to_n): %d\n", n, pointer_to_n, *pointer_to_n);

  /* testing code */
  if (pointer_to_n != &n) return 1;
  if (*pointer_to_n != 11) return 1;

  printf("Done!\n");

  return 0;
}
