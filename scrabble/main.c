#include <ctype.h>
#include <stdio.h>
#include <string.h>

int check_letter(char letter) {
  letter = tolower(letter);

  if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'l' ||
      letter == 'n' || letter == 'o' || letter == 'r' || letter == 's' ||
      letter == 't' || letter == 'u') {
    return 1;
  }

  else if (letter == 'd' || letter == 'g') {
    return 2;
  }

  else if (letter == 'b' || letter == 'c' || letter == 'm' || letter == 'p') {
    return 3;
  }

  else if (letter == 'f' || letter == 'h' || letter == 'v' ||
           letter == 'w' && letter == 'y') {
    return 4;
  }

  else if (letter == 'k') {
    return 5;
  }

  else if (letter == 'j' || letter == 'x') {
    return 8;
  }

  else if (letter == 'q' || letter == 'z') {
    return 8;
  }

  return 0;
}

int main(void) {
  char player1[64];
  char player2[64];
  int success1;
  int success2;
  int total1 = 0;
  int total2 = 0;

  printf("Player 1: ");

  success1 = scanf("%63[^\n]", player1);

  while (getchar() != '\n')
    ;

  printf("Player 2: ");

  success2 = scanf("%63[^\n]", player2);

  while (getchar() != '\n')
    ;

  for (int i = 0; i < strlen(player1); i++) {
    total1 += check_letter(player1[i]);
  }

  for (int i = 0; i < strlen(player2); i++) {
    total2 += check_letter(player2[i]);
  }

  if (total1 > total2) {
    printf("Player 1 wins!\n");
  } else if (total1 < total2) {
    printf("Player 2 wins!\n");
  } else if (total1 == total2) {
    printf("Tie!\n");
  }
}
