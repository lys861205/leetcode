/*
 * 字符串压缩
*/

#include <string>
#include <stdio.h>

using namespace std;

string compress(const string& s)
{
  if (s.size() <= 2) {
    return s;
  }
  string out;
  char prev = s[0];
  int cnt = 1;
  for (int i=1; i < s.size(); ++i) {
    if (s[i] == prev) {
      cnt++;
    }else {
      out.push_back(prev);
      out += to_string(cnt);
      prev = s[i];
      cnt = 1;
    }
  }
  if (cnt) {
    out.push_back(prev);
    out += to_string(cnt);
  }
  if (out.size() > s.size()) {
    return s;
  } else {
    return out;
  }
}

int main()
{
  string s = "aabcccccaaa";
  printf("%s\n", compress(s).c_str());
  return 0;
}
