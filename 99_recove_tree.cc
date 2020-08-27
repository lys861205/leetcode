/*
 * 恢复一颗BST树
*/

#include "Tree.h"

Tree* pre = nullptr;
Tree* l = nullptr;
Tree* r = nullptr;

void recoveTree(Tree* root)
{
  if (!root) return;
  recoveTree(root->left);
  if (pre && root->value < pre->value)
  {
    l = (l==nullptr) ? pre : l;
    r = root;
  }
  pre = root;
  recoveTree(root->right);
}

int main()
{
  Tree* root = BSTCreate(7);
  {
    Tree* l = BSTCreate(2);
    Tree* r = BSTCreate(6);
    root->left = l;
    root->right = r;
    Tree* l1 = BSTCreate(1);
    Tree* r1 = BSTCreate(3);
    l->left = l1;
    l->right = r1;

    Tree* l2 = BSTCreate(5);
    Tree* r2 = BSTCreate(4);
    r->left = l2;
    r->right = r2;
  }
  Print(root, 3, '*');
  recoveTree(root);
  if (l && r) {
    swap(l->value, r->value); 
  }
  Print(root, 3, '*');
  return 0;
}
