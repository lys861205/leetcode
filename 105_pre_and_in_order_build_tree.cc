/*
 * 从前序与中序遍历结果构造二叉树
*/
#include <stdio.h>
#include "Tree.h"


Tree* BuildTree(int* preorder, int prestart, int preend, int* inorder, int instart, int inend)
{
  if (prestart > preend || instart > inend) {
    return nullptr;
  }
  Tree* root = BSTCreate(preorder[prestart]);
  for (int i=instart; i < inend; ++i) {
    if (inorder[i] == preorder[prestart]) {
      root->left = BuildTree(preorder, prestart+1, prestart+i-instart, inorder, instart, i-1);
      root->right = BuildTree(preorder, prestart+i-instart+1, preend, inorder, i+1, inend);
    }
  }
  return root;
}

int main()
{
  int preorder[] = {3, 9, 20, 15, 7, 8};
  int inorder[] = {9, 3, 15, 20, 7, 8};
  Tree* root = BuildTree(preorder, 0, 5, inorder, 0, 5);
  Print(root, 2, '*');
  return 0;
}
