#include <stdio.h>
#include <string>

using namespace std;

string result;

bool IsPalindrome(string& result)
{
  size_t l = 0;
  size_t r = result.size() - 1;
  while (l < r) {
    if (result[l] != result[r]) {
      return false;
    }
    ++l;
    --r;
  }
  return true;
}

int backstrace(string& s, int size, int pos)
{
  if (result.size() > 0 && IsPalindrome(result)) {
    printf("[");
    for (size_t i = 0; i < result.size(); ++i) {
      printf("%c", result[i]);
    }
    printf("]\n");
  }
  if (result.size() == size) {
    return 0;
  }
  for (int i=pos; i < s.size(); ++i) {
    result.push_back(s[i]);
    backstrace(s, size, i+1);
    result.pop_back();
  }
  return 0;
}

int main()
{
  string s = "aab";
  backstrace(s, s.size(), 0);
  return 0;
}
