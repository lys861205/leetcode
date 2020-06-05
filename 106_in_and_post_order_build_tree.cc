/*
 * 从中序与后续遍历序列构造二叉树
*/

#include <stdio.h>
#include "Tree.h"

Tree* BuildTree(int* post, int poststart, int postend, int* in, int instart, int inend)
{
  if (poststart > postend || instart > inend) {
    return nullptr;
  }
  Tree* root = BSTCreate(post[postend]);
  for (int i=instart; i <= inend; ++i) {
    if (in[i] == post[postend]) {
      root->left = BuildTree(post, poststart, poststart+i-instart-1, in, instart, i-1);
      root->right = BuildTree(post, poststart+i-instart, postend-1, in, i+1, inend);
    }
  }
  return root;
}

int main()
{
  int inorder[] = {9,3,15,20,7};
  int postorder[] = {9,15,7,20,3};
  Tree* root = BuildTree(postorder, 0, 4, inorder, 0, 4);
  Print(root, 2, '*');
  return 0;
}

