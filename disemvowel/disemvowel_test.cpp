#include <gtest/gtest.h>

#include "disemvowel.h"

void compare_constants(char* test, const char* control) {
  /*
  @Param test: char
  @Param control: char

  Takes two strings, disemvowels the test string (test), 
  then compares the result with a pre-stripped string (control)
  with a test assertion.

  */
  char const* result = disemvowel(test); 
  ASSERT_STREQ(control, result);

  if(strcmp(result,"") != 0){
    free((void*) result);
  }
}

TEST(Disemvowel, HandleEmptyString) {
  compare_constants((char*) "","");
}

TEST(Disemvowel, HandleNoVowels) {
  compare_constants((char*) "pqrst","pqrst");
}

TEST(Disemvowel, HandleOnlyVowels) {
  compare_constants((char*) "aeiouAEIOUOIEAuoiea","");
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  compare_constants((char*) "Morris, Minnesota","Mrrs, Mnnst");
}

TEST(Disemvowel, HandlePunctuation) {
  compare_constants((char*) "An (Unexplained) Elephant!", "n (nxplnd) lphnt!");
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';

  compare_constants((char*) str, "xyz");
  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
