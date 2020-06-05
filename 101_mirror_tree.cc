/*
 * 对称二叉树
*/

#include <stdio.h>
#include "Tree.h"

bool IsMirrorTree(Tree* l, Tree* r)
{
  if (l==NULL && r==NULL) return true;
  if (!l || !r) return false;
  if (l->value != r->value) return false;
  if (!IsMirrorTree(l->left, r->right)) {
    return false;
  }
  if (!IsMirrorTree(l->right, r->left)) {
    return false;
  }
  return true;
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
  l2->left = l4;
  r2->right = r4;

  printf("%d\n", IsMirrorTree(root->left, root->right));
  return 0;
}
