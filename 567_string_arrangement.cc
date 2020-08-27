/*
 * 字符串排列
*/

#include <string>
#include <stdio.h>
#include <unordered_map>

using namespace std;


bool checkInclusion(string s1, string s2)
{
  
  unordered_map<char, int> window;
  unordered_map<char, int> needs; 

  for (auto c : s2) {
    needs[c]++;
  }
  int l=0, r=0;
  int match = 0;
  while (r < s1.size()) {
    char c = s1[r];
    if (needs.count(c)) {
      window[c]++;
      if (window.count(c) == needs.count(c)) {
        match++;
      }
    }
    ++r;
    while (needs.size() == match) {
      if ((r-l) == s2.size()) return true;
      char c1 = s1[l];
      if (needs.count(c1)) {
        window[c1]--;
        if (window[c1] < needs[c1]){
          match--;
        }
      }
      ++l;
    }
  }
  return false;
}

int main()
{
  string s1 = "eidbaooo";
  string s2 = "abo";
  printf("%s\n", checkInclusion(s1, s2) ? "True" : "False");
  string s3 = "abe";
  printf("%s\n", checkInclusion(s1, s3) ? "True" : "False");
  return 0;
}
