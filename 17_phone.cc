#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<char, string> map = {
  {'2', "abc"},
  {'3', "def"},
  {'4', "ghi"},
  {'5', "jkl"},
  {'6', "mno"},
  {'7', "pqrs"},
  {'8', "tuv"},
  {'9', "wxyz"}
};
std::vector<string> backstrace(string& s, int n)
{
  vector<string> v;
  if (n == 1) {
    string letters = map[s[0]];
    for (int i=0; i < letters.size(); ++i) {
      v.push_back(string(1, letters[i]));
    }
  }
  else {
    std::vector<string> vec = backstrace(s, n-1);
    string letters = map[s[n-1]];
    for (int i=0; i < letters.size(); ++i) {
      for (size_t j=0; j < vec.size(); ++j) {
        string vv = vec.at(j);
        vv.append(1, letters[i]);
        v.push_back(vv);
      }
    }
  }
  return v;
}

int main()
{
  std::string ss = "2857496";
  vector<string> v = backstrace(ss, ss.size());
  printf("size: %d\n", v.size());
  for (size_t i=0; i < v.size();++i) {
    printf("%s ", v[i].c_str());
  }
  printf("\n");
  return 0;
}
