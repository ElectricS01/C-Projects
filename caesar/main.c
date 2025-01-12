#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int is_number(const char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isdigit(str[i]))
      return 0;
  }
  return 1;
}

int main(int argc, char *argv[]) {

  if (argc != 2 || !is_number(argv[1])) {
    printf("Usage: ./caesar key\n");
    return 1;
  }

  char text[64];
  int success;
  int total = 0;

  printf("plaintext:  ");

  success = scanf("%63[^\n]", text);

  while (getchar() != '\n')
    ;

  int g = atoi(argv[1]) % 26;

  for (int i = 0; text[i] != '\0'; i++) {
    if (islower(text[i])) {
      printf("%c", 'a' + ((text[i] - 'a' + g) % 26));
    } else if (isupper(text[i])) {
      printf("%c", 'A' + ((text[i] - 'A' + g) % 26));
    } else {
      printf("%c", text[i]);
    }
  }

  printf("\n");
}
