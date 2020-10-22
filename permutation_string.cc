#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;


//查找s2中字符串的排列是否包含s1
bool PermutationString(const string& s2, const string& s1)
{
  unordered_map<char, int> window, need;
  for (auto c : s1) {
    need[c]++;
  }

  int left = 0, right = 0;
  int match = 0;
  while (right < s2.size()) {
    char c = s2[right];
    right++;

    window[c]++;
    if (need.count(c)) {
      if (need[c] == window[c]) {
        match++;
      }
    }
    
    while (match == need.size()) {
      if (right - left == need.size()) return true;
      char d = s2[left];
      ++left;
      if (need.count(d)) {
        if (need[c] == window[c]) {
          match--;
        }
      }
      window[d]--;
    }
  }
  return false;
}


int main()
{
  string s1 = "ab";
  string s2 = "eidbaooo";
  printf("%s\n", PermutationString(s2, s1) ? "True" : "False");

  {
    string s1 = "ab";
    string s2 = "aidieboo";
    printf("%s\n", PermutationString(s2, s1) ? "True" : "False");
  }
  return 0;
}
