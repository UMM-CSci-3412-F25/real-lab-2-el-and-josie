#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>



#include "disemvowel.h"

bool is_vowel(char c) {
  /*
  @Param c: char
  @Returns bool

  Takes a character and returns a boolean based on whether or not
  it is a vowel*

  *True: Vowel, False: Consonant
  */
  c = tolower(c);
  bool isVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
  return isVowel;
}

char *disemvowel(char *str) {
  /*
  @Param str: char
  @Returns char

  Takes a string and returns a version of the string
  stripped of it's vowels
  */

  char *tmp;
  char *string;
  size_t size = 0; // Size of temp string


  // If no valid string is passed, return empty
  if (str == NULL) {
    return (char*) "";
  }

  tmp = (char*) calloc ((strlen(str) + 1), sizeof(char));

  for (size_t i = 0; i < strlen(str); i++) {
  // If is_vowel(string[i]), add to temp array
    if (!is_vowel(str[i])) {
      tmp[size] = str[i];
      size++;
    }
  }

  string = (char*) calloc ((size + 1), sizeof(char));
  strncpy(string, tmp, size + 1);
  free(tmp);
  
  // If no valid string, or empty string, return empty
  if (size <= 0) {
    free(string);
    return (char*) "";
  }

  return string;
}