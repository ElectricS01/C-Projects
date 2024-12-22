#include <stdio.h>

int main(void) {
  int n;
  int success;
  int total = 0;

  do {
    n = 0;
    printf("Change owed: ");

    success = scanf("%d", &n);

    while (getchar() != '\n')
      ;

  } while (success != 1 || n < 0 || n > 300);

  do {
    if (n > 24) {
      n -= 25;
      total += 1;
    } else if (n > 9) {
      n -= 10;
      total += 1;
    } else if (n > 4) {
      n -= 5;
      total += 1;
    } else if (n > 0) {
      n -= 1;
      total += 1;
    }

  } while (n > 0);

  printf("%d\n", total);

  return 0;
}
