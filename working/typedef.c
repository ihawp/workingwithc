#include <stdio.h>
#include <string.h>


typedef struct {
  char name[25];
  char password[12];
  int id;
} User;

int main() {
  User user1 = {"warren", "wow12", 100};

  printf("%s\n", user1.name);
  printf("%s\n", user1.password);
  printf("%d\n", user1.id);

  return 0;
}
