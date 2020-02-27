#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAX 1000
int main ()
{
  char c;
  char str[MAX];
  List *list = init_history();
  printf("# - quit\n& - print history\n!(num) - see string inputed at that number!\n");
   while(1) {
    printf("$ ");
     fgets(str, MAX, stdin);
     char *word = str;
     if(word[0] == 0x23) {
	exit(1);
     }else if(word[0] == 0x21) {
       int id = (int)(word[1]);
       get_history(list, id); 
     }else if(word[0] == 0x26) {
       printf("Here is your history!\n");
       print_history(list);
     }
     char **token = tokenize(word);
     add_history(list, word);
   }
  return 0;
}
