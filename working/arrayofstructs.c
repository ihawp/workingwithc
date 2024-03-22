#include <stdio.h>
#include <string.h>

typedef struct {
  char name[12];
  float gpa;
} Student;

int main() {
  Student student1 = {"Spongebob", 3.0};
  Student student2 = {"Spongebob2", 2.0};

  Student students[] = {student1, student2};  

  for (int i = 0; i < sizeof(students)/sizeof(students[0]); i++) {
    printf("%-12s | ", students[i].name);
    printf("%.3f\n", students[i].gpa);
  }

  return 0;
}
