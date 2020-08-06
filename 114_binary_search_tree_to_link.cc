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

/*
 * 迭代步骤
 * 1 寻找根节点左子树最右节点
 * 2 让最右节点的右指针指向根节点的右子树
 * 3 让根节点的右子树指向左子树
 * 4 让根节点的左子树指向NULL
 * 5 树的左边没有节点了，把根root赋值为root->right, 重复1,2,3,4,5步骤
*/

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


