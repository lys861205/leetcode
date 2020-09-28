#ifndef UTIL_TRIE_TREE_TRIE_TREE_INL_H_
#define UTIL_TRIE_TREE_TRIE_TREE_INL_H_

#include <map>
#include <string>
#include <set>
#include <vector>
#include "trie_tree.h"

template<typename Val>
void TrieTree<Val>::Put(const string& key, Val& value) {
  if (key.size() < min_trie_) {
    min_trie_ = key.size();
  }
  if (root_ == NULL) {
    root_ = new Node();
  }
  Node* node = root_;
  for (string::const_iterator it = key.begin(); it != key.end(); ++it) {
    char ch = *it;
    Node* temp = (*node->char_table)[ch];
    if (temp == NULL) {
      temp = new Node();
      temp->ch = ch;
      temp->parent = node;
      (*node->char_table)[ch] = temp;
    }
    node = temp;
  }
  if (node->values == NULL) {
    node->values = new set<Val> ();
  }
  node->values->insert(value);
}

template<typename Val>
bool TrieTree<Val>::FindInternal(const string &key,
                                 int begin_pos,
                                 bool full_match) const {
  if (root_ == NULL) return false;
  const Node* node = root_;
  for (string::const_iterator it = key.begin() + begin_pos; it != key.end();
       ++it) {
    typename map<char, Node*>::const_iterator tmp = node->char_table->find(*it);
    if (tmp == node->char_table->end())
      return false;
    node = tmp->second;
    if (!full_match && node->values != NULL && node->values->size() > 0)
      return true;
  }
  if (!full_match)
    return false;
  return node->values->size() > 0;
}

template<typename Val>
void TrieTree<Val>::GetInternal(const string& key,
                                int begin_pos,
                                bool full_match,
                                vector<Val>* result) const {
  if (root_ == NULL) return;
  const Node* node = root_;
  for (string::const_iterator it = key.begin() + begin_pos; it != key.end();
      ++it) {
    typename map<char, Node*>::const_iterator tmp = node->char_table->find(*it);
    if (tmp == node->char_table->end())
      return;
    node = tmp->second;
    if (!full_match && node->values != NULL && node->values->size() > 0) {
      for (typename set<Val>::const_iterator it = node->values->begin();
           it != node->values->end(); ++it)
        result->push_back(*it);
    }
  }
  if (full_match && node->values != NULL && node->values->size() > 0) {
    for (typename set<Val>::const_iterator it = node->values->begin();
         it != node->values->end(); ++it)
      result->push_back(*it);
  }
}

template<typename Val>
void TrieTree<Val>::SubTreeGet(const string& key,
                               int begin_pos,
                               vector<Val>* result) const {
  if (root_ == NULL) {
    return;
  }
  const Node* node = root_;
  for (string::const_iterator it = key.begin() + begin_pos; it != key.end();
      ++it) {
    typename map<char, Node*>::const_iterator tmp = node->char_table->find(*it);
    if (tmp == node->char_table->end()) {
      return;
    }
    node = tmp->second;
  }
  vector<const Node*> level_order;
  level_order.push_back(node);
  while (level_order.size() > 0) {
    node = level_order.front();
    level_order.erase(level_order.begin());
    if (node->values != NULL && node->values->size() > 0) {
      set<Val>* values = node->values;
      for (typename set<Val>::const_iterator it = values->begin();
           it != values->end(); ++it)
        result->push_back(*it);
    }
    typename map<char, Node*>::const_iterator it = node->char_table->begin();
    for (; it != node->char_table->end(); ++it)
      level_order.push_back(it->second);
  }
}

template<typename Val>
void TrieTree<Val>::Remove(const string& key) {
  if (root_ == NULL) {
    return;
  }
  Node* node = root_;
  for (string::const_iterator it = key.begin(); it != key.end(); ++it) {
    char ch = *it;
    Node* temp = (*(node->char_table))[ch];
    if (temp == NULL) {
      return;
    }
    node = temp;
  }
  RemoveNode(node);
}

template<typename Val>
void TrieTree<Val>::Remove(const string& key, Val& value) {
  if (root_ == NULL) {
    return;
  }
  Node* node = root_;
  for (string::const_iterator it = key.begin(); it != key.end(); ++it) {
    char ch = *it;
    Node* temp = (*(node->char_table))[ch];
    if (temp == NULL) {
      return;
    }
    node = temp;
  }
  node->values->erase(value);
  if (node->values->size() <= 0) {
    RemoveNode(node);
  }
}

template<typename Val>
void TrieTree<Val>::RemoveNode(Node* n) {
  Node* node = n;
  while (node->parent) {
    Node* parent = node->parent;
    parent->char_table->erase(node->ch);
    delete node;
    if (parent->char_table->size() > 0 ||
        parent->values->size() > 0) {
      break;
    } else {
      node = parent;
    }
  }
  min_trie_ = CountMinTrie(root_) - 1;
}

template<typename Val>
int TrieTree<Val>::CountMinTrie(Node* n) const {
  if (n->values->size() > 0) {
    return 1;
  }
  int trie = INT_MAX;
  typename map<char, Node*>::const_iterator it;
  for (it = n->char_table->begin(); it != n->char_table->end(); ++it) {
    int tmp = CountMinTrie(it->second);
    if (tmp < trie) {
      trie = tmp;
      if (trie <= 1) {
        break;
      }
    }
  }
  return trie + 1;
}


#endif  // UTIL_TRIE_TREE_TRIE_TREE_INL_H_
