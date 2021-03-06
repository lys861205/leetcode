/*
 * 输入：
 * aa:(11) bbb:(22) bbb:(22) 333 444
 *
 * 输出：hashmap
 * aa->11
 * bbb->22
 * ccc->333 444
*/

#include <stdio.h>
#include <unordered_map>
#include <string>

using namespace std;

void PraseString(const string& input, unordered_map<string, string>& hashmap)
{
  enum State {
    EKeyBegin = 1,
    EColon = 2,
    EExpectBracket = 3,
    EValueBegin = 4,
    EExpectSpace = 5
  };
  State s = EKeyBegin;
  string key;
  string value;
  for (auto & c : input) {
    switch(s) {
      case EKeyBegin:
        if (c == ':') {
          s = EColon;
        } 
        else if (c == ' ' && key.size() == 0) {
          //
        }
        else {
          key.push_back(c);
        }
      break;
      case EColon:
        if (c == ' ') {
          s = EExpectBracket;
        }
        else if (c == '(') {
          s = EValueBegin;
        }
      break;
      case EExpectBracket:
        if (c == '(') {
          s = EValueBegin;
        }
      break;
      case EValueBegin:
        if (c == ')') {
          hashmap[key] = value;
          key.clear();
          value.clear();
          //s = EExpectSpace;
          s = EKeyBegin;
        }
        else if (c == ' ' && value.size() == 0) {
          //pass
        }
        else {
          value.push_back(c);
        }
      break;
      case EExpectSpace:
        if (c == ' ') {
          s = EKeyBegin; 
        }
      break;
    }
  }
  if (key.size() && !value.size()) {
    hashmap["ccc"] = key;
  }
}

int main()
{
  //const string s = "aa: ( 1 1 ) b bb: ( 22)  bbb:( 22)   333   444";
  const string s = "authoruri:(13121dda0876adbb) author:(高玉胭) author:(高玉胭)湖北师范学院经济与";
  unordered_map<string, string> hm(32);
  PraseString(s, hm);
  for (auto& x : hm) {
    printf("%s->%s\n", x.first.c_str(), x.second.c_str());
  }
  return 0;
}
