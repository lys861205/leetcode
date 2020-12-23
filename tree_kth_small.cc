/*
 * 230 第k小的树的值
*/

#include <stdio.h>
#include "Tree.h"

bool helper(Tree* root, int& count, int& value, int k)
{
  if (!root) return false;
  if (helper(root->left, count, value, k)) {
    return true;
  }
  count++;
  if (k == count) {
    value = root->value;
    return true;
  }
  if (helper(root->right, count, value, k)) {
    return true;
  }
}
int kthSmallest(Tree* root, int k)
{
  int count = 0;
  int kth_value = 0;
  helper(root, count, kth_value, k);
  return kth_value;
}


int main()
{
  Tree* root = BSTCreate(3);
  AddLeft(root, 2);
  AddRight(root, 4);
  Print(root, 3, '*');
  printf("%d\n", kthSmallest(root, 3));
  printf("%d\n", kthSmallest(root, 2));
  printf("%d\n", kthSmallest(root, 1));
  return 0; 
}
