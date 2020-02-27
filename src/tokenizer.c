#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

#define true 1
#define false 0

/*This method will get the length of the entire string*/
int word_length(char *str)
{
  int i;
  for (i = 0; str[i] != '\0'; ++i);
  return i;
}

/*This method will return true (non-zero) if c is
a whitespace ('\t' or ' '). Zero terminators
are not printable (therefore false)*/
int space_char(char c)
{
  return (c == 0x20  || c == "\t") ? true : false;
}

/*This method will return true (non-zero) if c is a non-
whitespace character (not tab or space). Zero terminators
are not printable (therefore false)*/
int non_space_char(char c)
{
  return (space_char(c) != true) ? true : false;
}

/*Returns a pointer to the first character of 
the word inside the string. Returns a zero 
pointer if str does not contain any words. */
char *word_start(char *str)
{
  for (; space_char(*str) || *str == '\0'; str++) {
    ;
  }
  return str;
}

/*Returns a pointer to the last character in the
last word in the entire string. Returns a zero pointer
if str does not contain any space characters. */
char *word_end(char *str)
{
  for (; non_space_char(*str) || *str == '\0'; str++) {
    ;
  }
  return str;
}

/*This method counts the number
  of words in the string argument*/
int count_words(char *str)
{
  int total = 1;
  for(int i = 0; i < word_length(str); i++) {
    if(space_char(str[i])) {
      total++;
    }
  }
  return total;
}
/*turns the str that is passed into a copy pointer to be
used in the tokenize method */
char *copy_str(char *inStr, short len)
{
  char *copy;
  copy = (char*) malloc (len + 1);
  int i;
  for (i = 0; i < len; inStr++, i++) {
    copy[i] = *inStr;
  }
  copy[i] = '\0';
  return copy;
}

/*Passes in a str and this method will break down each word an put it 
token array that has each word seperated */
char **tokenize(char* str) {
  int total = count_words(str);
  char **token;
  token = (char**) malloc (total);
  int i;
  for(i = 0; i < total; i++) {
    char* s = word_start(str);
    char *e = word_end(s);
    token[i] = copy_str(s, (e - s));
    str = word_start(e);
    printf("tokenize word %d: %s\n",(i + 1), token[i]);
  }
  return token;
}

/*prints all tokens. */
void print_tokens(char **tokens)
{
  for (int i = 0; *tokens !='\0'; i++) {
    printf("tokenize word #%d: %s\n", (i + 1),*tokens);
    ++tokens;
  }
}

/*releases all tokens using free */
void free_tokens(char **tokens)
{
  for (int i = 0; *(tokens + i) != '\0'; i++) {
    free(*(tokens + i));
  }
  free(tokens);
}
