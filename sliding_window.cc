#include <stdio.h>
#include <unordered_map>
#include <string>
#include <limits.h>

using namespace std;

string SlidingWindow(const string& s, const string& t)
{
  unordered_map<char, int> need, window;
  for (char c : t) {
    need[c]++;
  }
  int match = 0;
  int left = 0, right = 0;
  int len = INT_MAX;
  int start = 0;
  while (right < s.size()) {
    char c = s[right];
    right++;
    window[c]++;
    if (need.count(c)) { 
      if (window[c] == need[c]) {
        match++;
      }
    }

    while (match == need.size()) {
      if (right-left < len) {
        start = left;
        len = right - left;
      }

      char d = s[left];
      ++left;

      if (need.count(d) && (window[d] == need[d])) {
        match--;
      }
      window[d]--;
    }
  }
  return s.substr(start, len);
}

int main()
{
  string s = "ADOBECODEBANC";
  string t = "ABC";
  printf("%s\n",  SlidingWindow(s, t).c_str());
  return 0;
}
