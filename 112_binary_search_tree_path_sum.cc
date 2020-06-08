/*
 * 二叉树路径和等于指定的目标和
*/

#include <stdio.h>
#include "Tree.h"

bool HasPath(Tree* root, int target)
{
  if (!root) return false;
  int sum = target - root->value;
  if (root->left == NULL && root->right == NULL) {
    return sum == 0;
  }
  return HasPath(root->left, sum) || HasPath(root->right, sum);
}

int main()
{
  Tree* root = BSTCreate(10);
  Tree* l1 = BSTCreate(9);
  Tree* r1 = BSTCreate(11);
  //root->left = l1;
  root->right = r1;

  Tree* l2 = BSTCreate(12);
  Tree* r2 = BSTCreate(13);
  r1->left = l2;
  r1->right = r2;

  Tree* l3 = BSTCreate(12);
  Tree* r3 = BSTCreate(13);

  r2->left = l3;
  r2->right = r3;
  Print(root, 3, '*');
  printf("%d\n", HasPath(root, 33));
  printf("%d\n", HasPath(root, 34));
  return 0;
}
