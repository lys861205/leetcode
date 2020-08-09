/* * 二叉树转换成链表 */ 

#include "Tree.h"


Tree* Tree2Link(Tree* root)
{
  Tree* pr = root;
  while (pr) 
  {
    if (pr->left) 
    {
      Tree* l = pr->left;
      while (l->right) {
        l = l->right;
      }
      l->right = pr->right;
      pr->right = pr->left;
      pr->left = nullptr;
    }
    pr = pr->right;
  }
  return root;
}

int main()
{
  Tree* root = BSTCreate(5);
  BSTAdd(root, 4);
  BSTAdd(root, 6);
  BSTAdd(root, 3);
  Print(root, 3, '*');
  Print(Tree2Link(root), 3, '*');
  return 0; 
}
