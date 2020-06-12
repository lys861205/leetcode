/*
 * 在二叉树中查找列表
*/

#include <stdio.h>
#include "Tree.h"

bool FindLink(Tree* root, int* a, int n, int pos)
{
  if (pos == n) {
    return true;
  }
  if (!root) {
    return false;
  }
  if (root->value == a[pos]) {
    return FindLink(root->left, a, n, pos+1) || 
           FindLink(root->right, a, n, pos+1);
  }
  return false;
}

bool existLink(Tree* root, int* a, int n)
{
  if (!root) return false;
  if (FindLink(root, a, n, 0)) {
    return true;
  }
  return existLink(root->left, a, n) || existLink(root->right, a, n);
}

int main()
{
  Tree* root = BSTCreate(1);
  Tree* l1 = BSTCreate(2);
  Tree* r1 = BSTCreate(3);
  root->left = l1;
  root->right = r1;
  Tree* l2 = BSTCreate(12);
  Tree* r2 = BSTCreate(13);
  r1->left = l2;
  r1->right = r2;
  Tree* r3 = BSTCreate(14);
  r2->right = r3;
  Print(root, 3, '*');
  int a[] = {1, 3, 12};
  printf("%d\n", existLink(root, a, 3));
  return 0;
}
