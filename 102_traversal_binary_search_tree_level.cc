/*
 * 遍历二叉树的层
*/

#include <stdio.h>
#include "Tree.h"
#include <queue>
#include <vector>
using namespace std;

vector<vector<int> > LevelTree(Tree* root)
{
  vector<vector<int> > res;
  queue<Tree*> q;
  q.push(root);
  while (!q.empty()) {
    int sz = q.size();
    vector<int> nodes(sz, 0);
    for (int i=0; i < sz; ++i) {
      Tree* t = q.front();
      q.pop();
      if (t) nodes[i] = t->value;
      if (t->left) {
        q.push(t->left);
      }
      if (t->right) {
        q.push(t->right);
      }
    }
    res.emplace_back(nodes);
  }
  return res;
}

int main()
{
  Tree* root = BSTCreate(6); 
  /*
  root = BSTAdd(root, 5);
  root = BSTAdd(root, 4);
  root = BSTAdd(root, 3);

  root = BSTAdd(root, 7);
  root = BSTAdd(root, 8);
  root = BSTAdd(root, 9);
  */
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
  vector<vector<int> > res = LevelTree(root);
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


