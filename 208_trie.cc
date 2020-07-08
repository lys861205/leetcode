/*
 * 前缀树的实现
*/
#include <string>
using namespace std;

class Trie {
private:
  bool isEnd;
  Trie* next[26];

public:
  Trie():isEnd(false) {
    for (int i=0; i < 26; ++i) {
      next[i] = nullptr;
    }
  }
  void insert(const string& word)
  {
    Trie* t = this;
    for (char ch : word) {
      if (nullptr == t->next[ch-'a']) {
        t->next[ch-'a'] = new Trie;
      }
      t = t->next[ch-'a'];
    }
    t->isEnd = true;
  }
  bool search(const string& word) 
  {
    Trie* t = this;
    for (char ch : word) {
      t = t->next[ch-'a'];
      if (nullptr == t) {
        return false;
      }
    }
    return t->isEnd;
  }
  bool startsWith(const string& prefix)
  {
    Trie* t = this;
    for (char ch : prefix) {
      t = t->next[ch-'a'];
      if (nullptr == t) {
        return false;
      }
    }
    return true;
  }
};


int main()
{
  Trie t;
  t.insert("hello");
  t.insert("world");
  printf("%d\n", t.search("hello"));
  printf("%d\n", t.search("hllo"));
  printf("%d\n", t.startsWith("he"));
  printf("%d\n", t.startsWith("xe"));
  return 0;
}

