/*
 * 包含字符的最小子串
*/

#include <string>
#include <unordered_map>
#include <set>

using namespace std;

string minSubString(string& s, string& t)
{
  unordered_map<char, int> windows;
  unordered_map<char, int> needs;
  for (auto c : t) {
    needs[c]++;
  }
  int l = 0;
  int r = 0;
  int match = 0;
  int min_len = 0x7FFFFFFF;
  int start = 0;
  while (r < s.size()) {
    int c = s[r];
    if (needs.count(c)) {
      windows[c]++;
      if (windows[c] == needs[c]) {
        match++;
      }
    }
    ++r;
    while (needs.size() == match) {
      if ((r-l) < min_len) {
        start = l;
        min_len = r-l;
      }
      char c = s[l];
      if (needs.count(c)) {
        windows[c]--;
        if (windows[c] < needs[c]) {
          match--;
        }
      }
      ++l;
    }
  }
  return (min_len != 0x7FFFFFFF) ? s.substr(start, min_len) : "";
}

int main()
{
  string s = "ADOBECODEBANC";
  string t = "ABC";
  printf("%s\n", minSubString(s, t).c_str());
  return 0;
}
