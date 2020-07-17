/*
 * URL空格全部替换成%20
*/

#include <stdio.h>

void UrlSpaceReplace(char* str, int len)
{
  int numSpaces;
  for (int i=0; i < len; ++i) {
    if (str[i] == ' ') {
      ++numSpaces;
    }
  }
  int resize = len + 2 * numSpaces;
  int i = resize - 1;
  for (int j = len -1; j >= 0; --j) {
    if (str[j] != ' ') {
      str[i--] = str[j];
    } else {
      str[i--] = '0';
      str[i--] = '2';
      str[i--] = '%';
    }
  }
}

int main()
{
  char str[] = "Mr John Smith         ";
  UrlSpaceReplace(str, 13);
  printf("%s\n", str);
  return 0;
}
