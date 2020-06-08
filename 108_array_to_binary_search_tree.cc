/*
将有序数组转换成二叉搜索树 
*/
#include <stdio.h>
#include "Tree.h"


Tree* ArrayToBTS(int* a, int l, int r)
{
  if (l > r) {
    return NULL;
  }
  int m = (l+r)/2;
  Tree* root = BSTCreate(a[m]);
  root->left = ArrayToBTS(a, l, m-1);
  root->right = ArrayToBTS(a, m+1, r);
  return root;
}

int main()
{
  int a[] = {-10, -3, 0, 5, 9};
  Tree* root = ArrayToBTS(a, 0, 4);
  Print(root, 2, '*');
  return 0;
}
