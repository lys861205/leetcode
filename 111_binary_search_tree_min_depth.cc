/*
 二叉树最小深度
*/

#include <stdio.h>
#include "Tree.h"
#include <algorithm>

int minDepth(Tree* root)
{
  if (!root) return 0;
  int l = minDepth(root->left) + 1;
  int r = minDepth(root->right) + 1;
  return std::min(l, r);
}

int main()
{
  Tree* root = BSTCreate(10);
  Tree* l1 = BSTCreate(9);
  Tree* r1 = BSTCreate(11);
  //root->left = l1;
  root->right = r1;

  Tree* l2 = BSTCreate(12);
  Tree* r2 = BSTCreate(13);
  r1->left = l2;
  r1->right = r2;

  Tree* l3 = BSTCreate(12);
  Tree* r3 = BSTCreate(13);

  r2->left = l3;
  r2->right = r3;

  printf("%d\n", minDepth(root));
  return 0;
}
