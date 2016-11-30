#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
  char input[256];
  printf("What would you like to do? ");
  fgets(input, sizeof(input), stdin);
  //input[strlen(input) - 1] = 0;
  *(strchr(input, '\n')) = NULL;

  char *temp = input;
  char *argv[256];
  int i = 0;
  while (temp){
    argv[i] = strsep(&temp, " ");
    i++;
  }
  argv[i] = 0;
  int s = 0;
  for (; argv[s] != NULL; s++)
    printf("\targv[%d]: %s\n", s, argv[s]);
  execvp(argv[0], argv);
  printf("hello\n");
  return 0;
}
