#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  char text[512];
  int success;
  int total = 0;
  int l = 1;
  int s = 0;
  int o = 0;

  printf("Text: ");

  success = scanf("%511[^\n]", text);

  while (getchar() != '\n')
    ;

  for (int i = 0; i <= strlen(text); i++) {
    if (text[i] == ' ') {
      l++;
    } else if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
      s++;
    } else if (text[i] == '"' || text[i] == ':' || text[i] == ',') {
      o++;
    } else if (i == strlen(text)) {
      float res =
          (int)round(0.0588 * (double)(i - l - s - o) / (double)(l) * 100 -
                     0.296 * (double)s / (double)(l) * 100 - 15.8);
      if (res < 1) {
        printf("Before Grade 1\n");
      } else if (res >= 16) {
        printf("Grade 16+\n");
      } else {
        printf("Grade %i\n",
               (int)round(0.0588 * (double)(i - l - s - o) / (double)(l) * 100 -
                          0.296 * (double)s / (double)(l) * 100 - 15.8));
      }
    }
  }
}
