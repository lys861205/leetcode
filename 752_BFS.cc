#include <stdio.h>
#include <string>
#include <queue>
#include <set>

using namespace std;

string UpOne(std::string& str, int i)
{
  string s = str;
  if (s[i] == '9') {
    s[i] = '0';
  }
  else {
    s[i] += 1;
  }
  return s;
}

string DownOne(std::string& str, int i)
{
  string s = str;
  if (s[i] == '0') {
    s[i] = '9';
  }
  else {
    s[i] -= 1;
  }
  return s;
}

int OpenLock(const string& target)
{
  queue<string> q;
  q.push("0000");
  
  set<string> visited;
  visited.insert("0201");
  visited.insert("0101");
  visited.insert("0102");
  visited.insert("1212");
  visited.insert("2002");

  int step = 0;

  while (!q.empty()) {
    int sz = q.size();
    for (int i = 0; i < sz; ++i) {
      string cur = q.front();
      q.pop();
      // if (visited.count(cur)) {
      //   continue;
      // }
      if (cur == target) {
        return step;
      }
      for (size_t j=0; j < cur.size(); ++j) {
        string up   = UpOne(cur, j);
        if (visited.count(up)==0) {
          q.push(up);
          visited.insert(up);
        }
        string down = DownOne(cur, j);
        if (visited.count(down)==0) {
          q.push(down);
          visited.insert(down);
        }
      }
      ++step;
    }
  }
  return -1;
}

int main()
{
  printf("%d\n", OpenLock("0202"));
  return 0;
}
