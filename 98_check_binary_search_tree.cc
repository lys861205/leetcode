/*
 * 验证二叉搜索树, 给定一颗树是否是有效二叉搜索树
*/

#include <stdio.h>
#include "Tree.h"

bool IsVaildBTS(Tree* root)
{
  if (!root) return true;
  if (!IsVaildBTS(root->left)){
    return false;
  }
  if (!IsVaildBTS(root->right)) {
    return false;
  }
  if (root->left) {
    if (root->value < root->left->value) {
      return false;
    }
  }
  if (root->right) {
    if (root->value > root->right->value) {
      return false;
    }
  }
  return true;
}

int main()
{
  Tree* root = BSTCreate(2);
  Tree* l = BSTCreate(4);
  Tree* r = BSTCreate(1); 
  root->left = l;
  root->right = r;
  printf("%d\n", IsVaildBTS(root));
  root->left = r;
  root->right = l;
  printf("%d\n", IsVaildBTS(root));
  return 0;
}
