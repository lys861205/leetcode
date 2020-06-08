/*
 * 给定一个二叉树，判断是否是平衡二叉树
*/
#include <stdio.h>
#include "Tree.h"
#include <cmath>
#include <algorithm>

int   depth(Tree* root)
{
  if (!root) return 0;
  int left  =  depth(root->left) + 1;
  int right =  depth(root->right) + 1;
  return max(left, right);
}
bool  IsBalance(Tree* root)
{
  if (!root) return true;
  int l = depth(root->left);
  int r = depth(root->right);
  if (abs(l-r) > 1) return false;
  return IsBalance(root->left) && IsBalance(root->right);
}

int main()
{
  Tree* root = BSTCreate(1); 
  Tree* l2 = BSTCreate(2); 
  Tree* r2 = BSTCreate(2); 
  root->left = l2;
  root->right = r2;

  Tree* l3 = BSTCreate(3); 
  Tree* r3 = BSTCreate(3); 
  l2->left = l3;
  r2->right = r3;

  Tree* l4 = BSTCreate(4); 
  Tree* r4 = BSTCreate(4); 
  l3->left = l4;
  r3->right = r4;
  printf("%d\n", IsBalance(root));
  return 0;
}


