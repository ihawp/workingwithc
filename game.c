#include <stdio.h>


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

char winner;
char enemies[10];

// DEFINE FUNCTIONS
char movePlayer(char moveKey, int playerVelocity, int playerPosition);
int checkEnemyPositions();
char checkPlayerPosition(int playerPosition);

int main() {
  winner = ' ';
  Player player1 = {3, {0,0}, {5,0}};

  do {
    int pPlayerVelocity = *player1.velocity;
    int pPlayerPosition = *player1.position;

    checkEnemyPositions(); // check where the enemeies are and if they are on track to hit the player
    movePlayer('W', pPlayerVelocity, pPlayerPosition); // move the new player based on the given char (update position, based on velocity applied)
    checkPlayerPosition(pPlayerPosition); // set to within bounds if out of bounds, etc
    printf("%d\n", pPlayerVelocity);
    winner = 'I';
  } while (winner == ' ');

  printf("Winner: %c", winner);

  return 0;
}

/*
    Checks values or some shit yah fam!
    Checks for the players current position stored ideally in player.pos
    Keeps the player within the playspace
*/
char checkPlayerPosition(int playerPosition) {
// then move player
// then check values
//should move player toward center of screen always  
  return ' ';
}

/*
    REF in CHECKPLAYERPOSITION();
    This function would ideally be removed in an actual version of the game
    Will check x and y to see if any enemies are on track to hit the player
*/
int checkEnemyPositions() {
  for (int i = 0; i < 5; i++) {
    printf("%d\n", i);
    printf("enemy position checked\n");
  }
  return 0;
}

/*
    Changes the players position after stuff to new stuff
*/
char movePlayer(char moveKey, int playerVelocity, int playerPosition) {
   
  printf("%d\n", playerVelocity);
  printf("%d\n", playerPosition);
  return ' ';
}

