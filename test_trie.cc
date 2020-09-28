#include "trie_tree.h"
#include <stdio.h>

int main()
{
  TrieTree<string>* tr = new TrieTree<string>(); 
  string value("hello");
  tr->Put("www.test", value);
  string value1("C++");
  tr->Put("www", value1);
  string value2("golang");
  tr->Put("www", value2);
  string value3("中国人");
  tr->Put("www", value3);
  vector<string> r;
  tr->Get("www", &r);
  for (vector<string>::const_iterator it = r.begin(); 
        it != r.end(); ++it) {
    printf("%s ", it->c_str());
  }
  printf("\n");
  return 0;
}
