/*
 * 在二叉树每层找到最大值
*/

#include <stdio.h>
#include "Tree.h"
#include <vector>
#include <queue>

using namespace std;

vector<int> findMaxValues(Tree* root)
{
  vector<int> res;
  if (!root) {
    return res;
  }
  queue<Tree*> q;
  q.push(root);
  while (!q.empty()) {
    int sz = q.size();
    int max = -1;
    for (int i=0; i < sz; ++i) {
      Tree* t = q.front();
      q.pop();
      if (t->left) q.push(t->left);
      if (t->right) q.push(t->right);
      if (t->value > max) {
        max = t->value;
      }
    }
    res.push_back(max);
  }
  return res;
}

int main()
{
  Tree* root = BSTCreate(1);
  Tree* l1 = BSTCreate(2);
  Tree* r1 = BSTCreate(3);
  root->left = l1;
  root->right = r1;

  Tree* l2 = BSTCreate(5);
  Tree* r2 = BSTCreate(6);
  l1->left = l2;
  l1->right = r2;

  Tree* l3 = BSTCreate(7);
  Tree* r3 = BSTCreate(8);

  l2->left = l3;
  l2->right = r3;
  Print(root, 3, '*');
  vector<int> res = findMaxValues(root);
  printf("[");
  for (size_t i=0; i < res.size(); ++i) {
    printf("%d ", res[i]);
  }
  printf("]\n");
  return 0;
}



