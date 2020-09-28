#ifndef UTIL_TRIE_TREE_TRIE_TREE_H_
#define UTIL_TRIE_TREE_TRIE_TREE_H_

#include <map>
#include <string>
#include <set>
#include <vector>
#include <climits>

using namespace std;

template <typename Val>
class TrieTree {
 public:
  TrieTree() {
    root_ = NULL;
    min_trie_ = INT_MAX;
  }
  ~TrieTree() {
    delete root_;
  }

  // put a value identified by key into trie tree.
  // if value is already exists, trie tree is not changed.
  // if key is shorter than GetMinTrie(), GetMinTrie value is changed
  void Put(const string& key, Val& value);

  // remove all values identified by key
  // may be cause GetMinTrie() value changed.
  void Remove(const string& key);
  // remove all values identified by key.
  // may be cause GetMinTrie() value changed
  // if the value is the only identified by given key.
  void Remove(const string& key, Val& value);

  //////////// Find //////////////
  // return true if there is a prefix in tree
  bool Find(const string& key) const {
    return Find(key, 0);
  }
  // return true if there is a prefix in tree
  bool Find(const string& key, int begin_pos) const {
    return FindInternal(key, begin_pos, false);
  }

  // return true if there is a matched string in tree
  bool FullMatchFind(const string& key) const {
    return Find(key, 0);
  }
  // return true if there is a matched string in tree
  bool FullMatchFind(const string& key, int begin_pos) const {
    return FindInternal(key, begin_pos, true);
  }

  //////////// Get //////////////
  // get all values identified by longgest prefix of key to result
  void Get(const string& key, vector<Val>* result) const {
    Get(key, 0, result);
  }
  // get all values identified by substring of key from begin_pos into result
  void Get(const string& key, int begin_pos, vector<Val>* result) const {
    GetInternal(key, begin_pos, false, result);
  }

  // push all values identified by key to result
  void FullMatchGet(const string& key, vector<Val>* result) const {
    FullMatchGet(key, 0, result);
  }
  // push all values identified by key from begin_pos into result
  void FullMatchGet(const string& key,
                    int begin_pos, vector<Val>* result) const {
    GetInternal(key, begin_pos, true, result);
  }

  // push all values identified by key to result
  void SubTreeGet(const string& key, vector<Val>* result) const {
    SubTreeGet(key, 0, result);
  }
  // push all values identified by key from begin_pos into result
  void SubTreeGet(const string& key, int begin_pos, vector<Val>* result) const;

  int GetMinTrie() const {
    return min_trie_;
  };

 private:
  struct Node {
    Node() {
      ch = '\0';
      parent = NULL;
      char_table = new map<char, Node*>();
      values = new set<Val>();
    };
    ~Node() {
      delete values;
      typename map<char, Node*>::iterator it = char_table->begin();
      for (; it != char_table->end(); ++it) {
        delete it->second;
      }
      delete char_table;
    };
    char ch;
    Node* parent;
    map<char, Node*>* char_table;
    set<Val>* values;
  };
  void RemoveNode(Node* node);
  int CountMinTrie(Node* node) const;
  bool FindInternal(const string &key, int begin_pos, bool full_match) const;
  void GetInternal(const string &key, int begin_pos, bool full_match,
                   vector<Val> *result) const;

  Node* root_;
  int min_trie_;
  set<Val> empty_set_;
};

#include "trie_tree-inl.h"

#endif  // UTIL_TRIE_TREE_TRIE_TREE_H_
