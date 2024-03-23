// DEFINE VARIABLES
char playing;
typedef struct {
  int lives;
  int level;
  int position[2];
  int velocity[2];
} Player;
typedef struct {
  int position[2];
  int velocity[2];
} Enemy;

// DEFINE FUNCTIONS
char movePlayer(char moveKey, int position[], int velocity[], int size);
char updateEnemyPositions(Enemy* enemies, int position[], int velocity[], int* totalEnemyCount);
void checkPlayerPosition(int position[]);
void formatEnemies(Enemy* enemies);
int makeEnemies(Enemy* enemies);
int checkInterjection(Enemy* enemies, int position[]);
void checkPossibleInterjection(Enemy* enemies, int position[]);
int resetEnemies(Enemy* enemies);