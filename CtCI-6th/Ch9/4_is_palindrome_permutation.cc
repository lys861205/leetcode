/*
 *  判断是否为某个回文排列之一
*/

#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

bool isPalindromePermutation(const string& s)
{
  int spaces = 0;
  unordered_map<char, int> cnt;
  for (char  c : s) {
    if (c >= 'A' && c <='Z') {
      c = c + 32;
    }
    else if (c == ' ') {
      spaces++;
      continue;
    }
    cnt[c]++;
  }
  int odd =  (s.size()-spaces) % 2;
  for (const auto& m : cnt) {
    if (m.second % 2 == 1)  {
      --odd; 
    }
    if (odd < 0) {
      return false; 
    }
  }
  return true;
}

int main()
{
  string s = "Tact Coa";
  string s1 = "Tactaoa";
  printf("%s\n", isPalindromePermutation(s)? "true" : "false");
  printf("%s\n", isPalindromePermutation(s1)? "true" : "false");
  return 0;
}
