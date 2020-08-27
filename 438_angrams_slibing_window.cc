/*
 *
*/

#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> findAnagrams(string& s, string& t)
{
  unordered_map<char, int> window;
  unordered_map<char, int> needs;
  for (auto c : t) {
    needs[c]++;
  }
  int l=0, r=0;
  vector<int> res;
  int match = 0;
  while (r < s.size()){
    char c = s[r];
    if (needs.count(c)) {
      window[c]++;
      if (window[c] == needs[c]) {
        ++match;
      }
    }
    ++r;

    while (needs.size() == match) {
      if ((r-l) == t.size()) res.push_back(l);
      char c = s[l];
      if (needs.count(c)){
        window[c]--;
        if (window[c] < needs[c]){
          --match;
        }
      }
      ++l;
    }
  }
  return res;
}

int main()
{
  {
    string s = "cbaebabacd";
    string t = "abc";
    auto res = findAnagrams(s, t);
    for (auto i=0; i < res.size(); ++i) {
      printf("%d ", res[i]);
    }
    printf("\n");
  }

  {
    string s = "abab";
    string t = "ab";
    auto res = findAnagrams(s, t);
    for (auto i=0; i < res.size(); ++i) {
      printf("%d ", res[i]);
    }
    printf("\n");
  }
  return 0;
}

