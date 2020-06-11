/*
 * 合并2个二叉树
*/

#include <stdio.h>
#include "Tree.h"

Tree* mergeTree(Tree* root, Tree* t)
{
  if (!root) {
    root = t; 
    return root;
  }
  if (!t) {
    return root;
  }
  root->value += t->value;
  root->left = mergeTree(root->left, t->left);
  root->right = mergeTree(root->right, t->right);
  return root;
}

int main()
{
  Tree* root = BSTCreate(1);
  Tree* l1 = BSTCreate(10);
  Tree* r1 = BSTCreate(8);
  root->right = r1;
  r1->right = l1;

  Tree* root2 = BSTCreate(1);
  {
    Tree* l1 = BSTCreate(20);
    Tree* r1 = BSTCreate(16);
    root2->left = r1;
    r1->left = l1;
  }

  Print(root, 3, '*');
  Print(root2, 3, '*');
  root = mergeTree(root, root2);
  Print(root, 3, '*');
  return 0;
}
