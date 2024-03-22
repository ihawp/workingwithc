#include <stdio.h>

void printAge(int* age) {

  printf("you are %d years old", *age);

}


void main() {

  int age = 21;

  int* pAge = NULL; // if not yet assigning a value it is good practice to assign null
  pAge = &age;

  printf("address of age: %p\n", pAge);
  printf("value of age: %i\n", age);

  printf("value at stored address: %d\n", *pAge);  

  printf("size of age: %d bytes\n", sizeof(age));
  printf("size of pAge: %d bytes\n", sizeof(pAge));

  printAge(pAge);
}
