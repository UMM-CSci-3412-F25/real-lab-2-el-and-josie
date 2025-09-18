#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>



#include "disemvowel.h"

bool is_vowel(char c) {
  c = tolower(c);
  bool isVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
  return isVowel;
}

char *disemvowel(char *str) {
  char *tmp;
  char *string;
  size_t size = 0;
  // Allocate memory for length of string
  // for length of string 
  tmp = (char*) malloc (strlen(str) + 1);
  for (size_t i = 0; i < strlen(str); i++) {
  // if is_vowel(string[i]), add to temp array
    if (!is_vowel(str[i])) {
      tmp[size] = str[i];
      size++;
    }
  }

  string = (char*) malloc (size + 1);
  // string = tmp;
  strncpy(string, tmp, size + 1);
  free(tmp);
  
  if(size <= 0) {
    free(string);
    return (char*) "";
  }
  return (char*) string;
}


// g++ -Wall -g -o disemvowel_test disemvowel_test.cpp disemvowel.c -lgtest -pthread -std=c++0x