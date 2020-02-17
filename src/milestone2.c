#include <stdio.h>

#ifndef _TOKENIZER_
#define _TOKENIZER_
#define true 1
#define false 0

/*This method will get the length of the entire string*/
int word_length(char *str) {
  int total = 0;
  while(str[total] != '\0') {
    total++;
  }
  return total;
}

/*This method will return true (non-zero) if c is
a whitespace ('\t' or ' '). Zero terminators
are not printable (therefore false)*/
int space_char(char c) {
  return (c == 0x20  || c == "\t") ? true : false;
}

/*This method will return true (non-zero) if c is a non-
whitespace character (not tab or space). Zero terminators
are not printable (therefore false)*/
int non_space_char(char c) {
  return (c != 0x20 || c != "\t") ? true : false;
}

/*Returns a pointer to the first character of 
the word inside the string. Returns a zero 
pointer if str does not contain any words. */
char *word_start(char *str) {
  int j = 0;
  char *ip;
  ip = &str[j];
  return *ip;
}

/*Returns a pointer to the last character in the
last word in the entire string. Returns a zero pointer
if str does not contain any space characters. */
char *word_end(char *str) {
  int i = 0;
  for(i; i < word_length(str) -  1; i++) {
    ;
  }
  char *ip;
  ip = &str[i];
  return *ip;
}

/*This method counts the number
  of words in the string argument*/
int count_words(char *str) {
  int total = 1;
  for(int i = 0; i < word_length(str); i++) {
    if(space_char(str[i])) {
      total++;
    }
  }
  return total;
}

#endif
