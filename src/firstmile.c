#include <stdio.h>

#define MAX 1000
int main () {
  printf("$ ");
  char str[MAX];
  fgets(str, MAX, stdin);
  printf("%s\n", str);
  return 0;
}
