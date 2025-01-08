#include <stdio.h>
#include <string.h>

#define LIMIT 18

int main(void) {
  char input[LIMIT];
  int success;
  int valid = 0;
  int total = 0;

  printf("Number: ");

  success = scanf("%17[^\n]", input);

  while (getchar() != '\n')
    ;

  if (success && strlen(input) <= LIMIT - 2 && strlen(input) >= LIMIT - 6) {
    for (int i = strlen(input) - 1; i > -1; i--) {
      int number = input[i] - '0';

      if ((i % 2 == 1 && !(strlen(input) % 2)) ||
          (i % 2 == 0 && strlen(input) % 2)) {
        total += number;
      } else {
        number = number * 2;

        total += number % 10;

        if (number > 9) {
          total += 1;
        }
      }
    }

    if (!(total % 10)) {

      if (input[0] == '3' && (input[1] == '7' || input[1] == '8') &&
          strlen(input) == 15) {
        printf("AMEX\n");
      }

      else if (input[0] == '5' &&
               (input[1] - '0' >= 1 && input[1] - '0' <= 5) &&
               strlen(input) == 16) {
        printf("MASTERCARD\n");
      }

      else if (input[0] == '4' &&
               (strlen(input) == 13 || strlen(input) == 16)) {
        printf("VISA\n");
      }

      else {
        printf("INVALID\n");
      }
    } else {
      printf("INVALID\n");
    }
  } else {
    printf("INVALID\n");
  }
}
