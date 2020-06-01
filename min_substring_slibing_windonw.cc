#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string minWindow(string s, string t)
{
  int start = 0, minLen = 0x7fffffff;
  int left =0, right = 0;
  unordered_map<char, int> window;
  unordered_map<char, int> needs;

  for(auto c: t) {
    needs[c]++;
  }

  int match = 0;

  while (right < s.size()) {
    char c1 = s[right];
    if (needs.count(c1)) {
      window[c1]++;
      if (window[c1] == needs[c1]) {
        match++;
      }
    }
    right++;

    while (match == needs.size()) {
      if (right - left < minLen) {
        start = left;
        minLen = right - left;
      }
      char c2 = s[left];
      if (needs.count(c2)) {
        window[c2]--;
        if (window[c2] < needs[c2]) {
          match--; 
        }
      }
      left++;
    }
  }
  return (minLen == 0x7fffffff ? "": s.substr(start, minLen));
}

vector<int> findAnagrams(string s, string t)
{
  vector<int> res;
  int left =0, right = 0;
  unordered_map<char, int> window;
  unordered_map<char, int> needs;

  for(auto c: t) {
    needs[c]++;
  }

  int match = 0;

  while (right < s.size()) {
    char c1 = s[right];
    if (needs.count(c1)) {
      window[c1]++;
      if (window[c1] == needs[c1]) {
        match++;
      }
    }
    right++;

    while (match == needs.size()) {
      if ( (right - left) == t.size() ){
        res.push_back(left); 
      }
      char c2 = s[left];
      if (needs.count(c2)) {
        window[c2]--;
        if (window[c2] < needs[c2]) {
          match--; 
        }
      }
      left++;
    }
  }
  return res;
}
int main()
{
  string s = "ADOBECODEBANC"; 
  string t = "ABC";
  printf("%s\n", minWindow(s, t).c_str());
  printf("=====================\n");
  string s1 = "cbaebabacd";
  string t1 = "abc";
  vector<int> v = findAnagrams(s1, t1);
  for (size_t i=0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
  return 0;
}
