#include <string>
#include <stdio.h>
#include <unordered_map>
#include <algorithm>


using namespace std;

int lengthOfLongestSubString(string s)
{
  int maxlen = 0x80000000;
  int left = 0, right = 0;
  unordered_map<char, int> window;

  while (right < s.size()) {
    char c1 = s[right];
    window[c1]++;
    right++;
    while(window[c1] > 1) {
      char c2 = s[left];
      window[c2]--;
      left++;
    }

    maxlen = max(maxlen, right - left);
  }
  return maxlen;
}

int main()
{
  string s = "abcabcbb";
  printf("%d\n", lengthOfLongestSubString(s));
  string s1 = "bbbbb";
  printf("%d\n", lengthOfLongestSubString(s1));
  string s2 = "pwwkew";
  printf("%d\n", lengthOfLongestSubString(s2));
  return 0;
}
