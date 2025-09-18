#include <gtest/gtest.h>

#include "disemvowel.h"

int compare_consonants(const char* test, const char* control){
    char *cleaned = disemvowel((char*) control);
    printf("\n%s\n", cleaned);
    printf("\n%s\n", control);
    int result = strcmp(test, control);
    printf("\n%c\n", result);
    free(cleaned);
    // if(strcmp(cleaned,"") != 0){
    //     free(cleaned);
    // }
    return result;
}

TEST(Disemvowel, HandleEmptyString) {
  ASSERT_EQ(compare_consonants("", ""),0);
  // ASSERT_STREQ("", disemvowel((char*) ""));
}

TEST(Disemvowel, HandleNoVowels) {
  ASSERT_EQ(compare_consonants("pqrst", "pqrst"),0);
  // ASSERT_STREQ("pqrst", disemvowel((char*) "pqrst"));
}

TEST(Disemvowel, HandleOnlyVowels) {
  ASSERT_EQ(compare_consonants("aeiouAEIOUOIEAuoiea", ""),0);

  // ASSERT_STREQ("", disemvowel((char*) "aeiouAEIOUOIEAuoiea"));
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  ASSERT_EQ(compare_consonants("Morris, Minnesota", "Mrrs, Mnnst"),0);

  // ASSERT_STREQ("Mrrs, Mnnst",
	// 	      disemvowel((char*) "Morris, Minnesota"));
}

TEST(Disemvowel, HandlePunctuation) {
  ASSERT_EQ(compare_consonants("An (Unexplained) Elephant!", "n (nxplnd) lphnt!"),0);

  // ASSERT_STREQ("n (nxplnd) lphnt!", 
	// 	      disemvowel((char*) "An (Unexplained) Elephant!"));
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
  
  ASSERT_EQ(compare_consonants(str, "xyz"),0);

  // ASSERT_STREQ("xyz", disemvowel(str));

  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
