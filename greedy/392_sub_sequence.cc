/*
 * 判断子序列
*/

#include <string>
#include <stdio.h>

using namespace std;

bool IsSubSequence(const string& s, const string& t)
{
  for (int i =0, j = 0; i < t.size(); ++i) {
    if (j < s.size() && t[i] == s[j]) {
      ++j;
    }
    if (j == s.size()) {
      return true;
    }
  }
  return false;
}

int main()
{
  printf("%d\n", IsSubSequence("abc", "ahbgdc"));
  printf("%d\n", IsSubSequence("axc", "ahbgdc"));
  return 0;
}
