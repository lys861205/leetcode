/*
 * 二叉树的锯齿形层次遍历
*/
#include <stdio.h>
#include "Tree.h"
#include <deque>
#include <vector>

using namespace std;


vector<vector<int> > TravelTreeLevel(Tree* root)
{
  vector<vector<int> > res;
  deque<Tree*> dq;
  dq.push_front(root);
  bool on = true;
  while (!dq.empty()) {
    int sz = dq.size();
    vector<int> nodes(sz, 0);
    if (on) {
      for (int i=0; i < sz; ++i) {
        Tree* tr = dq.front();
        dq.pop_front();
        if (tr) {
          nodes[i] = tr->value;
        }
        if (tr->right) dq.push_back(tr->right);
        if (tr->left) dq.push_back(tr->left);
      }
      res.emplace_back(nodes);
    }
    else {
      for (int i=0; i < sz; ++i) {
        Tree* tr = dq.back();
        dq.pop_back();
        if (tr) {
          nodes[i] = tr->value;
        }
        if (tr->left) dq.push_front(tr->left);
        if (tr->right) dq.push_front(tr->right);
      }
      res.emplace_back(nodes);
    }
    on = !on;
  }
  return res;
}

int main()
{
  Tree* root = BSTCreate(6); 
  Tree* l2 = BSTCreate(4); 
  Tree* r2 = BSTCreate(7); 
  root->left = l2;
  root->right = r2;

  Tree* l3 = BSTCreate(9); 
  Tree* r3 = BSTCreate(10); 
  l2->left = l3;
  l2->right = r3;

  Tree* l4 = BSTCreate(12); 
  Tree* r4 = BSTCreate(11); 
  r2->left = l4;
  r2->right = r4;
  vector<vector<int> > res = TravelTreeLevel(root);
  printf("[\n");
  for (size_t i=0; i < res.size();++i) {
    printf(" [");
    for (size_t j=0; j < res[i].size(); ++j) {
      printf("%d ", res[i][j]); 
    }
    printf(" ]\n");
  }
  printf("]\n");
  return 0;
}

