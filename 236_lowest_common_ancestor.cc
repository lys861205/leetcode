/*
 * 共同祖先
*/
#include <stdio.h>
#include "Tree.h"

Tree* lowestCommonAncestor(Tree* root, Tree* p, Tree* q)
{
  if (!root) return nullptr;
  if (root == p || root == q) return root;
  Tree* l = lowestCommonAncestor(root->left, p, q);
  Tree* r = lowestCommonAncestor(root->right, p, q);
  if (l && r) {
    return root;
  } 
  else if (!l && !r) {
    return nullptr;
  }
  return l==nullptr ? r : l;
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
  Tree* ancestor = lowestCommonAncestor(root, l3, r3);
  Print(ancestor, 3, '*');
  return 0;
}
