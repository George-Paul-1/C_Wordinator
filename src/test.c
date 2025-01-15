#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "lib.c"

// Very small test helpers
int failed = 0;
#define TEST(name) void name()
#define RUN_TEST(name) printf("\n\033[1m%s\n\033[0m", #name); name()
#define ASSERT(expr) if (!(expr)) { \
  failed = 1; \
  printf("\033[0;31mFAIL: %s\n\033[0m", #expr); \
} else { \
  printf("\033[0;32mPASS: %s\n\033[0m", #expr); \
}
#define ASSERT_STR_EQ(str1, str2) if (!(strcmp(str1, str2) == 0)) { \
  failed = 1; \
  printf("\033[0;31mFAIL: %s != %s\n\033[0m", str1, str2); \
} else { \
  printf("\033[0;32mPASS: %s == %s\n\033[0m", str1, str2); \
}
// End of test helpers

TEST(test_wordinator) {
  char res[100] = {"\0"}; 

  wordinator(100, res);
  ASSERT_STR_EQ(res, "one hundred") 
  strcpy(res, "");

  wordinator(200, res);
  ASSERT_STR_EQ(res, "two hundred")
  strcpy(res, "");

  wordinator(120, res);
  ASSERT_STR_EQ(res, "one hundred and twenty")
  strcpy(res, "");

  wordinator(115, res);
  ASSERT_STR_EQ(res, "one hundred and fifteen")
  strcpy(res, "");

  wordinator(217, res);
  ASSERT_STR_EQ(res, "two hundred and seventeen")
  strcpy(res, "");

  wordinator(1000, res);
  ASSERT_STR_EQ(res, "one thousand")
  strcpy(res, "");

  wordinator(1600, res);
  ASSERT_STR_EQ(res, "one thousand six hundred")
  strcpy(res, "");

  wordinator(1007, res);
  ASSERT_STR_EQ(res, "one thousand and seven")
  strcpy(res, "");

  wordinator(1010, res);
  ASSERT_STR_EQ(res, "one thousand and ten"); 
  strcpy(res, "");

  wordinator(3517, res);
  ASSERT_STR_EQ(res, "three thousand five hundred and seventeen"); 
  strcpy(res, "");

  wordinator(9478, res);
  ASSERT_STR_EQ(res, "nine thousand four hundred and seventy eight"); 
  strcpy(res, "");

  wordinator(59, res);
  ASSERT_STR_EQ(res, "fifty nine"); 
  strcpy(res, "");

  wordinator(10, res);
  ASSERT_STR_EQ(res, "ten"); 
  strcpy(res, "");

  wordinator(4, res);
  ASSERT_STR_EQ(res, "four"); 
  strcpy(res, "");

  wordinator(10000, res);
  ASSERT_STR_EQ(res, "ten thousand"); 
  strcpy(res, "");

  wordinator(10100, res);
  ASSERT_STR_EQ(res, "ten thousand one hundred"); 
  strcpy(res, "");

  wordinator(10007, res);
  ASSERT_STR_EQ(res, "ten thousand and seven"); 
  strcpy(res, "");
   
  wordinator(30607, res);
  ASSERT_STR_EQ(res, "thirty thousand six hundred and seven"); 
  strcpy(res, "");

  wordinator(100000, res);
  ASSERT_STR_EQ(res, "one hundred thousand"); 
  strcpy(res, "");

  wordinator(111000, res);
  ASSERT_STR_EQ(res, "one hundred and eleven thousand"); 
  strcpy(res, "");

  wordinator(120000, res);
  ASSERT_STR_EQ(res, "one hundred and twenty thousand"); 
  strcpy(res, "");

  wordinator(17, res);
  ASSERT_STR_EQ(res, "seventeen"); 
  strcpy(res, "");
  
  wordinator(956000, res);
  ASSERT_STR_EQ(res, "nine hundred and fifty six thousand"); 
  strcpy(res, "");

  wordinator(650123, res);
  ASSERT_STR_EQ(res, "six hundred and fifty thousand one hundred and twenty three"); 
  strcpy(res, "");
}

TEST(test_string_assert) {
  ASSERT_STR_EQ("hello", "hello");
}

int main() {
  // Add a `RUN_TEST` line for each test function 
  RUN_TEST(test_wordinator);
  RUN_TEST(test_string_assert);
  return failed;
}
