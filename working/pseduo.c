#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  srand(time(0));

  int number1 = (rand() % 6) + 1;  

  printf("%d", number1);
}
