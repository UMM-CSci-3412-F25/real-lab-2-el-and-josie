#include <gtest/gtest.h>

#include "disemvowel.h"

// int compare_consonants(const char* test, const char* control){
//     char *cleaned = disemvowel((char*) control);
//     printf("\n!%s!\n", cleaned);
//     printf("!%s!\n", control);
//     int result = strcmp(test, control);
//     printf("\nResult: %d\n", result);
//     // free(cleaned);
//     if(strcmp(cleaned,"") != 0){
//         free(cleaned);
//     }
//     return result;
// }

void compare_constants(char* test, const char* control) {
  char const* result = disemvowel(test);
  ASSERT_STREQ(control, result);

  // free(test);
  // free((void*) result);

  if(strcmp(result,"") != 0){
    free((void*) result);
  }
  test = NULL;
  result = NULL;
}

TEST(Disemvowel, HandleEmptyString) {
  // ASSERT_EQ(compare_consonants("", ""),0);
  compare_constants((char*) "","");
  // ASSERT_STREQ("", disemvowel((char*) ""));
}

TEST(Disemvowel, HandleNoVowels) {
  // ASSERT_EQ(compare_consonants("pqrst", "pqrst"),0);
  // ASSERT_STREQ("pqrst", disemvowel((char*) "pqrst"));
    compare_constants((char*) "pqrst","pqrst");

}

TEST(Disemvowel, HandleOnlyVowels) {
  // ASSERT_EQ(compare_consonants("aeiouAEIOUOIEAuoiea", ""),0);

  // ASSERT_STREQ("", disemvowel((char*) "aeiouAEIOUOIEAuoiea"));
  compare_constants((char*) "aeiouAEIOUOIEAuoiea","");
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  // ASSERT_EQ(compare_consonants("Morris, Minnesota", "Mrrs, Mnnst"),0);

  // ASSERT_STREQ("Mrrs, Mnnst",
	// 	      disemvowel((char*) "Morris, Minnesota"));

  compare_constants((char*) "Morris, Minnesota","Mrrs, Mnnst");

}

TEST(Disemvowel, HandlePunctuation) {
  // ASSERT_EQ(compare_consonants("An (Unexplained) Elephant!", "n (nxplnd) lphnt!"),0);

  // ASSERT_STREQ("n (nxplnd) lphnt!", 
	// 	      disemvowel((char*) "An (Unexplained) Elephant!"));

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
  
  // char const* result = disemvowel(str);
  // ASSERT_STREQ("xyz", result);

  compare_constants((char*) str, "xyz");
  free(str);
  // free((void*) result);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
