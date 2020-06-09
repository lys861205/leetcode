/*
 *  翻转二叉树
*/

#include <stdio.h>
#include "Tree.h"

Tree* invertTree(Tree* root)
{
  if (!root) return root;
  invertTree(root->left);
  invertTree(root->right);
  Tree* l = root->left;
  Tree* r = root->right;
  root->left = r;
  root->right = l;
  return root;
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
  root = invertTree(root);
  Print(root, 3, '*');
  return 0;
}
