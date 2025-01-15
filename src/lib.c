#include <stdbool.h>

int processPlusHundredThousands(int n, char* res, char* ones[], char* tens[], char* teens[]); 
void wordinator(int n, char* res);
int processSubHundredThousands(int n, char* res, char* ones[], char* tens[], char* teens[]);

void wordinator(int n, char* res) {
  char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  char *tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
  char *teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

  if (n == 0) {
    strcpy(res, "zero");
    return;
  }
  n = processPlusHundredThousands(n, res, ones, tens, teens);
  n = processSubHundredThousands(n, res, ones, tens, teens);
}

int processSubHundredThousands(int n, char* res, char* ones[], char* tens[], char* teens[]) {
  if (n >= 1000) {      
        strcat(res, ones[n / 1000]);
        strcat(res, " thousand");
        n = n % 1000;
      
      if (n > 99) {
        strcat(res, " ");
      } else if (n > 0) {
        strcat(res, " and ");
      }
    }
    
    if (n >= 100) {
      strcat(res, ones[n / 100]);
      strcat(res, " hundred");
      n = n % 100;
      if (n > 0) {
        strcat(res, " and ");
      }
    }
    
    if (n == 0) {
      return n;
    }

    if (n >= 20 || n == 10) {
      strcat(res, tens[n/10]);
      n = n % 10;
      if (n > 0) {
        strcat(res, " ");
      }
    }

    if (n / 10 > 0) { 
      strcat(res, teens[n % 10]);
    } else if (n != 0) { 
      strcat(res, ones[n]);
    }
    return n;
}

int processPlusHundredThousands(int n, char* res, char* ones[], char* tens[], char* teens[]) { 
  if (n >= 100000) {
    strcat(res, ones[n / 100000]);
    strcat(res, " hundred");
    n = n % 100000;
    if (n > 0) {
      strcat(res, " and ");
    } else {
      strcat(res, " thousand");
    }
  } 
  if (n >= 10000) {
      if (n % 10000 >= 1000 && n < 20000) {
        strcat(res, teens[n / 10000]);
      } else {
        strcat(res, tens[n / 10000]);
      }
      if (n % 10000 >= 1000 && n > 20000) {
        strcat(res, " ");
        strcat(res, ones[(n % 10000) / 1000]);
      }
      strcat(res, " thousand");
      n = n % 1000;
      if (n > 99) {
        strcat(res, " ");
      } else if (n > 0) {
        strcat(res, " and ");
      }
    }
  return n;
}