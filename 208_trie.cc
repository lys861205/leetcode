/*
 * 前缀树的实现
*/
#include <string>
#include <vector>
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
  void suggest(const string& prefix, vector<string>& words)
  {
    Trie* t = this;
    for (char c : prefix) {
      t = t->next[c-'a'];
      if (nullptr == t) {
        return;
      }
    }
    if (t->isEnd) {
      words.push_back(prefix);
    }
    string word = prefix;
    match(t, word, words);
  }

  friend void match(Trie* t, std::string& word, vector<string>& words)
  {
    for (int i=0; i < 26; ++i) {
      Trie* tt = t->next[i];
      if (!tt) {
        continue;
      }
      word.push_back(i+'a');
      if (tt->isEnd) {
        words.push_back(word);
      }
      match(tt, word, words);
      word.pop_back();
    }
  }
};


int main()
{
  Trie t;
  t.insert("hello");
  t.insert("hell");
  t.insert("hewhe");
  t.insert("world");
  t.insert("help");
  printf("%d\n", t.search("hello"));
  printf("%d\n", t.search("hllo"));
  printf("%d\n", t.startsWith("he"));
  printf("%d\n", t.startsWith("xe"));
  printf("=============\n");
  vector<string> wds;
  t.suggest("he", wds);
  for (int i=0; i < wds.size(); ++i) {
    printf("%s\n", wds[i].c_str());
  }
  return 0;
}

