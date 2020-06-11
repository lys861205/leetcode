/*
  把二叉搜索树在转成累加树 
*/

#include <stdio.h>
#include "Tree.h"
int sum = 0;
void GreaterTree(Tree* root)
{
  if (!root) return;
  GreaterTree(root->right);
  root->value = root->value + sum;
  sum = root->value;
  GreaterTree(root->left);
}

int main()
{
  Tree* root = BSTCreate(1);
  Tree* l1 = BSTCreate(10);
  Tree* r1 = BSTCreate(8);
  root->right = r1;
  r1->right = l1;
  Print(root, 3, '*');
  GreaterTree(root);
  Print(root, 3, '*');
  return 0;
}



