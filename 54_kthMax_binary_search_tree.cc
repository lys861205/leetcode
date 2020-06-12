/*
 * 二叉搜索树第k大节点
*/

#include <stdio.h>
#include "Tree.h"

Tree* kthMaxTree(Tree* root, int& cnt, int k)
{
  if (!root) return NULL;
  Tree* l = kthMaxTree(root->left, cnt, k);
  if (l) return l;
  if (++cnt == k) return root;
  Tree* r = kthMaxTree(root->right, cnt, k);
  if (r) return r;
}

int main()
{
  Tree* root = BSTCreate(1);
  Tree* l1 = BSTCreate(2);
  Tree* r1 = BSTCreate(3);
  root->left = l1;
  root->right = r1;
  Tree* l2 = BSTCreate(4);
  Tree* r2 = BSTCreate(5);
  l1->left = l2;
  l1->right = r2;
  Tree* l3 = BSTCreate(6);
  Tree* r3 = BSTCreate(7);
  r1->left = l3;
  r1->right = r3;
  Print(root, 3, '*');
  int cnt = 0;
  for (int i=1; i < 8; ++i) {
    Tree* node = kthMaxTree(root, cnt, i);
    cnt = 0;
    printf("%d\n", node->value);
  }
  return 0;
}
