/*
 * 二叉树的最大深度
*/
#include <stdio.h>
#include "Tree.h"

int maxDepth(Tree* root)
{
  if (!root) return 0;
  int l = maxDepth(root->left);
  int r = maxDepth(root->right);
  return l > r ? (l+1) : (r+1);
}

int minDepth(Tree* root)
{
  if (!root) return 0;
  int l = maxDepth(root->left);
  int r = maxDepth(root->right);
  return l < r ? (l+1) : (r+1);
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

  Tree* l5 = BSTCreate(12);
  Tree* r5 = BSTCreate(11);
  l4->left = l5;
  l4->right = r5;
  printf("%d\n", maxDepth(root));
  printf("%d\n", minDepth(root));
  
  return 0;
}
