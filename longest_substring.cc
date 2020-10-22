#include <stdio.h>
#include <unordered_map>
#include <string>
#include <limits.h>
#include <algorithm>

using namespace std;


int LengthOfLongestSubString(const string& s)
{
  unordered_map<char, int> window;
  int left = 0, right = 0;
  int res = 0;
  while (right < s.size()) {
    char c = s[right++];
    window[c]++;

    while (window[c] > 1) {
      char d = s[left++];
      window[d]--;
    }

    res = max(res, right - left);
  }
  return res;
}

int main()
{
  {
    const string s = "abcabcbb";
    printf("%d\n", LengthOfLongestSubString(s));
  }

  {
    const string s = "bbbbbb";
    printf("%d\n", LengthOfLongestSubString(s));
  }

  {
    const string s = "pwwkew";
    printf("%d\n", LengthOfLongestSubString(s));
  }
  return 0;
}
