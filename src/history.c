#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/*Initialize the linked list to keep the history. */
List* init_history()
{
  List* new_list;
  new_list = (List *) malloc (sizeof(List));
  new_list->root = NULL;
  return new_list;
}

/*Add a history item to the end of the list.
List* list - the linked list
char* str - the string to store */
void add_history(List *list, char *str)
{
  Item *new_item; 
  new_item = (Item *) malloc(sizeof(Item));
  int string_size = word_length(str);
  char *copy = (char *) malloc (sizeof(char)*string_size + 1);
  int i;
  for (i = 0; i < string_size; i++) {
    *(copy + i) = *(str + i);
  }
  *(copy + i) = '\0';
  new_item->next = NULL;
  new_item->str = copy;
  Item *other;
  other = list->root;
  if (other == NULL) {
    new_item->id = 1;
    list->root = new_item;
  }else {
    while (other->next != NULL) {
      other = other->next;
    }
    other->next = new_item;
    new_item->id = other->id + 1;
  }
}

/*Retreive the string stored in the node where Item->id == id
List *list - the linked list
int id - the id of the Item to find  */
char *get_history(List *list, int id)
{
  Item *other;
  other = list->root;
  int current = 0;
  while(other->next != NULL && current != id) {
    other = other->next;
    current++;
  }
  printf("%s\n", other->str);
  return other->str;
}

/*Print the entire contents of the list*/
void print_history(List *list)
{
  Item *other;
  other = list->root;
  while (other->next != NULL) {
    printf("%s\n", other->str);
    other = other->next;
  }
   printf("%s\n", other->str);
}

/*Free the history list and the
strings its references. */
void free_history(List *list)
{
  Item *other;
  other = list->root;
  while(other->next != NULL) {
    other = list->root->next;
    free(list->root->str);
    free(list->root);
    list->root = other;
  }
  free(list->root->str);
  free(list->root);
  free(list);
}
