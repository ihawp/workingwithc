#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include "game.h"

int main() {
char playing = 'Y';
do {
  int totalEnemyCount = 0;
  int *pTOTAL = &totalEnemyCount;
  Player player1 = {3, 1, {300,300}, {0,0}};

  Enemy* enemies = malloc(10 * sizeof *enemies);
  resetEnemies(enemies);

  srand(time(0));

  do {
    char playerMove = ' ';
    printf("\nInput a move (W,A,S,D): ");
    scanf(" %c", &playerMove);
    playerMove = toupper(playerMove);

    movePlayer(playerMove, player1.position, player1.velocity, 2); // move the new player based on the given char (update position, based on velocity applied)
    checkPlayerPosition(player1.position); // set to within bounds if out of bounds, etc
    updateEnemyPositions(enemies, player1.position, player1.velocity, pTOTAL);
    checkPossibleInterjection(enemies, player1.position);
    if (totalEnemyCount/(player1.level*175) >= 1) {
      player1.level += 1;
      printf("\nYou beat level %d, now time for level %d!\n", player1.level - 1, player1.level);
    }
    if (checkInterjection(enemies, player1.position) != 0) {
      player1.lives--;
      printf("LIVES %d\n---------------------------------------------------------------------------------\n", player1.lives);
      resetEnemies(enemies);
    }
    printf("\nSCORE: %d\n", totalEnemyCount);
  } while (player1.lives != 0);
    printf("\nWould you like to play again? (Y/N)\n");
    scanf(" %c", &playing);
    playing = toupper(playing);
  if (playing == 'Y') {
    continue;
  } else {
    playing = 'N';
  }
} while (playing == 'Y');
  printf("\nThanks for playing\n");
  scanf(" %c", &playing);
  return 0;
}

void checkPlayerPosition(int position[]) {  
  if (position[0] > 600) {
    position[0] = 600;
  } else if (position[0] < 0) {
    position[0] = 0;
  }
  if (position[1] > 600) {
    position[1] = 600;
  } else if (position[1] < 0) {
    position[1] = 0;
  }
}


int makeEnemies(Enemy* enemies) {
  for (int i = 0; i < 10; i++) {
    // left or right determinant
    if (i % 2 > 0) {
      enemies[i].position[0] = rand() % 600;
      enemies[i].position[1] = 0;
      enemies[i].velocity[1] = rand() % 15;
    } else {
      enemies[i].position[0] = 0;
      enemies[i].position[1] = rand() % 600;
      enemies[i].velocity[0] = rand() % 15;
    }
  }
 return 1;
}

/*
    The rand() function is acting funky
    This function corrects enemies that have values far out of the proper range
*/
void formatEnemies(Enemy* enemies) {
  for (int i = 0; i < 10; i++) {
    if (enemies[i].position[0] > 0 && enemies[i].position[1] > 0) {
      enemies[i].position[0] = 0;
      enemies[i].position[1] = 57;
    } else if (enemies[i].position[0] > 600) {
      enemies[i].position[0] = 300;
    } else if (enemies[i].position[1] > 600) {
      enemies[i].position[1] = 300;
    }

    if (enemies[i].velocity[0] > 0 && enemies[i].velocity[1] > 0 && enemies[i].position[1] > 0) {
      enemies[i].velocity[0] = 7;
      enemies[i].velocity[1] = 0;
    } else if (enemies[i].velocity[0] > 0 && enemies[i].velocity[1] > 0 && enemies[i].position[0] > 0) {
      enemies[i].velocity[1] = 7;
      enemies[i].velocity[0] = 0;
    } else if (enemies[i].velocity[0] > 14) {
      enemies[i].velocity[0] = 7;
    } else if (enemies[i].velocity[1] > 14) {
      enemies[i].velocity[1] = 7;
    }
  }
}

int resetEnemies(Enemy* enemies) {
  if (makeEnemies(enemies)) {
    formatEnemies(enemies);
  }
  return 1;
}

char updateEnemyPositions(Enemy* enemies, int position[], int velocity[], int* totalEnemyCount) {
  for (int i = 0; i < 10; i++) {

    // UPDATE ENEMIES POSITION BY THEIR VELOCITY
    if (enemies[i].velocity[1] > 0) {
      enemies[i].position[1] += enemies[i].velocity[1];
    } else if (enemies[i].velocity[0] > 0) {
      enemies[i].position[0] += enemies[i].velocity[0];
    }

    // ENEMIES OUT OF BOUNDS CASE
    if (enemies[i].position[0] > 600 || enemies[i].position[1] > 600) {
      *totalEnemyCount += 1;
      if (enemies[i].velocity[0] > 0) {
        enemies[i].position[0] = 0;
        enemies[i].position[1] = rand() % 600;
      } else if (enemies[i].velocity[1] > 0) {
        enemies[i].position[1] = 0;
        enemies[i].position[0] = rand() % 600;
      }
    }

  }
  return 'T';
}

int checkInterjection(Enemy* enemies, int position[]) {
  for (int i = 0; i < 10; i++) {
    if (abs((enemies[i].position[0]+10) - (position[0]+15)) < 20 && abs((enemies[i].position[1]-10) - (position[1]-15)) <= 20) {
      return 1;
    }
  }
  return 0;
}

void checkPossibleInterjection(Enemy* enemies, int position[]) {
  for (int i = 0; i < 10; i++) {
    if (enemies[i].velocity[0] > 0) {
      if ((position[1] - 15) <= enemies[i].position[1] && enemies[i].position[1] <= (position[1] + 15)) {
        printf("\n!!!WARNING!!!\nPossible Interjection *>>>>*\n Enemy Y Coordinate: %d\n", enemies[i].position[1]);
      }
    } else if (enemies[i].velocity[1] > 0) {
      if ((position[0] - 15) <= enemies[i].position[0] && enemies[i].position[0] <= (position[0] + 15)) {
        printf("\n!!!WARNING!!!\nPossible Interjection *^^^^*\n Enemy X Coordinate: %d\n", enemies[i].position[0]);
      }
    }
  }
}

char movePlayer(char moveKey, int position[], int velocity[], int size) {
  switch (moveKey) {
    case ('W'):
      velocity[1] = 7;
      position[1] += velocity[1]; 
      break;
    case ('A'):
      velocity[0] = -7;
      position[0] += velocity[0];
      break;
    case ('S'):
      velocity[1] = -7;
      position[1] += velocity[1];
      break;
    case ('D'):
      velocity[0] = 7;
      position[0] += velocity[0];
      break;
    default:
      break;
  }

  velocity[0] = 0;
  velocity[1] = 0;

  printf("\nAfter Move: %c\n", moveKey);
  printf("Your Position (%d, %d)\n", position[0], position[1]);
  return 'T';
}



