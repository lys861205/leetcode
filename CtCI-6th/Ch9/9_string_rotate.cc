/*
 * 字符串轮转
*/

#include <string>
#include <stdio.h>

using namespace std;

bool isSubString(const string& s1, const string& s2)
{
  if (s1.size() != s2.size()) {
    return false;
  }

  string temp = s1+s2;
  if (temp.find(s2) != string::npos) {
    return true;
  }
  return false;
}

int main()
{
  string s1 = "waterbottle";
  string s2 = "erbottlewat";
  printf("%s\n", isSubString(s1, s2) ? "true" : "false");
  return 0;
}
