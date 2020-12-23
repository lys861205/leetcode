/*
 * 114 二叉树展开为链表
*/
#include <stdio.h>
#include "Tree.h"


void flatten(Tree* root)
{
  if (!root) return;
  Tree* p = root;
  while (p) {
    Tree* r = p;
    Tree* prev = p;
    while (p) {
      prev = p;
      p = p->right; 
    }
    prev->right = r->left;
    r->left = nullptr;
    p = r->right;
  }
}

void flatten2(Tree* root) 
{
  if (!root) return;
  Tree* p = root;
  Tree* prev = p;
  while (p) {
    prev = p;
    p = p->right;
  }
  prev->right = root->left;
  root->left = nullptr;
  flatten2(root->right);
}

int main()
{
  Tree* root = BSTCreate(5);
  Tree* ll = AddLeft(AddLeft(root, 4), 11);
  AddLeft(ll, 7);
  AddRight(ll, 2);
  Tree* rr= AddRight(root, 8);
  AddLeft(rr, 13);
  AddRight(AddRight(rr, 4), 1);
  Print(root, 3, '*');
  flatten2(root);
  Print(root, 3, '*');
  return 0;
}
