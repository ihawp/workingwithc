#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int openFile(char *file, char *text) {
  FILE *pF = fopen(file, "a");
  fprintf(pF, "\n%s", text);
  fclose(pF);
  return 0;
}

int main(void) {

  char file[256];
  char text[1024];

  printf("Create a new file:\n");
  scanf(" %255s", file);    

  printf("Input text to append to the file:\n");
  scanf(" %[^\n]255s", text);


  if (openFile(file, text) != 0) {
    printf("ERROR");	
  }

  return 0;
}
