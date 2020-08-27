/*
 * 无重复最长字串
*/

#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

int longSubStringNotrepated(string& s)
{
  unordered_map<char, int> window;
  int l=0, r=0;
  int Max = 0;
  while (r < s.size()) {
    char& c = s[r];
    window[c]++;
    ++r;

    while (window[c] > 1) {
      char c1 = s[l];
      window[c1]--;
      ++l;
    }
    Max = std::max(Max, r-l);
  }

  return Max;
}

int longSubStringNotRepated(string& s)
{
  char window[26] = {0};
  int l=0, r=0;
  int Max = 0;
  while (r < s.size()) {
    char& c = s[r];
    window[c-'a']++;
    ++r;

    while (window[c-'a'] > 1) {
      char c1 = s[l];
      window[c1-'a']--;
      ++l;
    }
    Max = std::max(Max, r-l);
  }

  return Max;
}

int main()
{
  {
    string s = "abcabcbb";
    printf("%d\n", longSubStringNotrepated(s));
  }
  {
    string s = "bbbbbbb";
    printf("%d\n", longSubStringNotRepated(s));
  }
  return 0;
}
