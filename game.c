#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

// DEFINE VARIABLES
int enemySize = 20;
int playerSize = 30;

typedef struct {
  int lives;
  int position[2];
  int velocity[2];
} Player;

typedef struct {
  int position[2];
  int velocity[2];
} Enemy;


// DEFINE FUNCTIONS
char movePlayer(char moveKey, int position[], int velocity[], int size);
char checkEnemyPositions(Enemy* enemies, int position[], int velocity[]);
void checkPlayerPosition(int position[], int size);

int main() {
  Player player1 = {3, {300,300}, {0,0}};
  Enemy* enemies = malloc(10 * sizeof *enemies);

  srand(time(0));

  // COULD BE MAKEENEMIES() FUNCTION:
  for (int i = 0; i < 10; i++) {
    // left or right determinant
    if (i % 2 > 0) {
      enemies[i].position[0] = rand() % 600;
      enemies[i].velocity[1] = rand() % 15;
    } else {
      enemies[i].position[1] = rand() % 600;
      enemies[i].velocity[0] = rand() % 15;
    }
    printf("\nPOSITION [%i]: %i, %i\n", i, enemies[i].position[0], enemies[i].position[1]);
    printf("VELOCITY [%i]: %i, %i\n", i, enemies[i].velocity[0], enemies[i].velocity[1]);
  }

  do {
    char playerMove = ' ';
    printf("\nInput a move (W,A,S,D):\n");
    scanf(" %c", &playerMove);
    playerMove = toupper(playerMove);
  
    movePlayer(playerMove, player1.position, player1.velocity, 2); // move the new player based on the given char (update position, based on velocity applied)
    checkPlayerPosition(player1.position, 2); // set to within bounds if out of bounds, etc
    checkEnemyPositions(enemies, player1.position, player1.velocity);
  
    player1.lives--;
  } while (player1.lives);

  return 0;
}

/*
    Keeps the player within playspace
    SHOULD BE VOID
*/
void checkPlayerPosition(int position[], int size) {
  
}

/*
    Will check enemy positions and determine if enemies are on track to hit the player
    It will make the player aware if enemies are on track to hit them (and maybe return a recommended move)
    It will then ask the player for an input (char) either W, A, S, or D to move up, left, down, right respectively
    Returns input to playermove variable in main();

    THIS COULD BE TWO FUNCTIONS OR SEPERATE: ONE WHERE ENEMIES ARE CHECKED AND PLAYER IS MADE AWARE AND THEN ANOTHER FUNCTIONS FOR SCANF OR SCANF IN MAIN()
*/
char checkEnemyPositions(Enemy* enemies, int position[], int velocity[]) {
  for (int i = 0; i < 10; i++) {

    /*
        implement logic to find which position the enemy has been placed in and add their velocity to the position
    */

    printf("\nenemy [%d] info: \nPOSITION: x: %d, y: %d, \nVELOCITY: x: %d, y: %d\n", i, enemies[i].position[0], enemies[i].position[1], enemies[i].velocity[0], enemies[i].velocity[1]);
  }
  return 'T';
}

/*
    Changes the players velocity to 7 in whichever direction they chose during the enemies check
    Then checks the players current position against the size of the canvas and corrects the player to be within bounds
*/
char movePlayer(char moveKey, int position[], int velocity[], int size) {
  printf("\nmove: %c\n", moveKey);
  printf("position 0: %d\n", position[0]);
  printf("position 1: %d\n", position[1]);
  
  /*
      technically velocity is not need for the player in this game as it will be presented essentially frame-by-frame
      asking you for a input over and over about where you would need to move
  */

  switch (moveKey) {
    case ('W'):
      velocity[1] = 7;
      position[1] += velocity[1]; 
      break;
    case ('A'):
      velocity[0] = -7;
      position[0] += velocity[1];
      break;
    case ('S'):
      velocity[1] = -7;
      position[1] += velocity[1];
      break;
    case ('D'):
      velocity[0] = 7;
      position[0] += velocity[1];
      break;
    default:
      break;
  }
  return 'T';
}

