#include <stdio.h>
#include "game.h"

int gameOn = 0;

int main(void) {
  do {
    // make a screen
    int value = printf("Input a number: ");
    scanf("%i", &value);
    if (value > 10) {
      printf("%i", value);
      gameOn = 1;
      gameFunction();
    }
  } while (gameOn == 0);
  return 0;
}

int gameFunction(void) {
  printf("goodjob\n");
  return 0;
}
