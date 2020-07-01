/*
 * 二叉树展开链表
*/

#include <stdio.h>
#include "Tree.h"

void flatten(Tree* root) { //递归调用，后序遍历
  if (!root) return;
  flatten(root->left);
  flatten(root->right);

  if (root->left) {
    Tree* l = root->left;
    while (l->right) {
        l = l->right;
      }
      l->right = root->right;
      root->right = root->left;
      root->left = NULL;
  }
}

void flatten2(Tree* root)
{
  while (root) {
    if (root->left) {
      Tree* lr = root->left;
      while (lr->right) {
        lr = lr->right;
      }
      lr->right = root->right;
      root->right = root->left;
      root->left = NULL;
    }
    root = root->right;
  }
}

int main()
{
  Tree* root = BSTCreate(5); 
  root = BSTAdd(root, 4);
  root = BSTAdd(root, 6);
  Print(root, 3, '*');
  flatten(root);
  while(root) {
    printf("%d ", root->value); 
    root = root->right;
  }
  printf("\n");
  return 0;
}


