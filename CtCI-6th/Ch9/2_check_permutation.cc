/*
 * 判断是否是重排字符串
*/

#include <stdio.h>
#include <unordered_map>
#include <string>

using namespace std;

//O(s1+s2)
bool isPermutation(const string &s1, const string &s2)
{
  if (s1.size() != s2.size()) {
    return false;
  }
  unordered_map<char, int> cnt;
  unordered_map<char, int> win;
  for (char c : s2) {
    cnt[c]++;
  }
  int r = 0;
  int match = 0;
  while (r < s1.size()) {
    char ch = s1[r];
    r++;
    if (cnt.count(ch)<=0) {
      return false;
    }
    win[ch]++;
    if (win[ch] == cnt[ch]) {
      match++; 
    }
  }
  if (match == cnt.size()) {
    return true;
  } else {
    return false;
  }
}

//O(s1+s2)
bool arePermutation(const string& s1, const string& s2)
{
  if (s1.size() != s2.size()) {
    return false;
  }
  int count[256] = {0};
  for (int i=0; i < s1.size(); ++i) {
    int v = s1[i];
    count[v]++;
  }
  for (int j=0; j < s2.size(); ++j) {
    int v = s2[j];
    count[v]--;
    if (count[v]<0) {
      return false;
    }
  }
  return true;
}

int main()
{
  string s1 = "Hello";
  string s2 = "lloHe";
  string s3 = "looHe";
  printf("%d\n", isPermutation(s1, s2));
  printf("%d\n", isPermutation(s1, s3));
  printf("====================================\n");
  printf("%d\n", arePermutation(s1, s2));
  printf("%d\n", arePermutation(s1, s3));
  return 0;
}

