#include <stdio.h>
#include <unordered_map>
#include <string>
#include <limits.h>
#include <vector>

using namespace std;

vector<int> FindAnagrams(const string& s, const string& t) 
{
  unordered_map<char, int> window, need;

  for (auto c : t) {
    need[c]++;
  }
  vector<int> res;
  int left = 0, right = 0;
  int match = 0;
  int size = s.size();
  while (right < size) {
    char c = s[right++];

    window[c]++;
    if (need.count(c) && need[c] == window[c]) {
      ++match; 
    }

    while (match == need.size()) {
      if (right - left == t.size()) {
        res.push_back(left);
      }
      char d = s[left++];
      if (need.count(d) && need[d] == window[d]) {
        --match; 
      }
      window[d]--;
    }
  }

  return std::move(res);
}

int main()
{
  const string s = "cbaebabacd";
  const string p = "abc";
  vector<int> res = FindAnagrams(s, p);
  for (int i=0; i < res.size(); ++i) {
    printf("%d ", res[i]);
  }
  printf("\n");
  return 0;
}

