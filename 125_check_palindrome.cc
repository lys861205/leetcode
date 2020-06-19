#include <stdio.h>
#include <string>
using namespace std;

bool isAlpha(char c) {
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
    return true;
  }else {
    return false;
  }
}
bool isNumber(char c) {
  if (c >= '0' && c <= '9'){
    return true;
  } else {
    return false;
  }
}
bool isPalindrome(string s) {
  int len = s.size();
  int i = 0;
  int j = len -1;
  while (i < j){
    if (!isAlpha(s[i]) && !isNumber(s[i])) {
      ++i;
      continue;
    }
    if (!isAlpha(s[j]) && !isNumber(s[j])) {
      --j;
      continue;
    } 
    if (s[i] == s[j] || tolower(s[i]) == tolower(s[j])) {
      ++i;
      --j;
    } else {
      return false;
    }
  }
  return true;
}

int main()
{
  string s = "0P";
  printf("%d\n", isPalindrome(s));
  return 0;
}
