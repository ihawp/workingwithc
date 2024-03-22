#include <stdio.h>
#include <ctype.h>

int main() {
  char questions[][100] = {"1. What year did the C language debut? ",
                           "2. Who is credited with creating C? ",
                           "3. What is the predecessor of C? "};

  char options[][100] = {"A. 1969", "B. 1972", "C. 1975", "D. 1999",
                         "A. Dennis Ritchie", "B. Nikola Tesla", "C. ur mom", "D. ur dad",
                         "A. Objective C", "B. B", "C. C++", "D. C#"};

  char answers[3] = {'B', 'A', 'B'};
  int numberOfQuestions = sizeof(questions)/sizeof(questions[0]);
  char guess;
  int score = 3;

  printf("Quiz game!\n");
  for (int i = 0; i < numberOfQuestions; i++) {
    printf("%s\n", questions[i]);
    for (int k = (i*4); k < (i*4) + 4; k++) {
      printf("%s\n", options[k]);
    }
    printf("Guess: ");
    scanf(" %c", &guess);

    guess = toupper(guess);


    if (guess == answers[i]) {
      printf("CORRECT!\n");
    } else {
      printf("WRONG!\n");
      score--;
    }
  }

  printf("FINAL SCORE: %d/%d\n", score, numberOfQuestions);
  return 0;
}
