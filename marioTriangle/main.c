#include <stdio.h>

int main(void) {
  int n;
  int success;

  do {
    n = 0;
    printf("Height: ");

    success = scanf("%d", &n);

    while (getchar() != '\n')
      ;

  } while (success != 1 || n < 1);

  for (int i = 0; i < n; i++) {
    for (int ii = n - i; ii > 0; ii--) {
      printf(" ");
    }
    for (int ii = 0; ii <= i; ii++) {
      printf("#");
    }
    printf("\n");
  }

  return 0;
}
