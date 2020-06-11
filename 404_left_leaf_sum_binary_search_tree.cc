/*
 * 左叶子之和
*/
#include <stdio.h>
#include "Tree.h"

void leftLeafSum(Tree* root, int& sum)
{
  if (!root) return;
  if (root->left && root->left->left == NULL && root->left->right == NULL) {
    sum += root->left->value;
  }
  leftLeafSum(root->left, sum);
  leftLeafSum(root->right, sum);
}

int main()
{
  Tree* root = BSTCreate(1);
  Tree* l1 = BSTCreate(2);
  Tree* r1 = BSTCreate(3);
  root->left = l1;
  root->right = r1;

  Tree* l2 = BSTCreate(5);
  Tree* r2 = BSTCreate(6);
  l1->left = l2;
  l1->right = r2;

  Tree* l3 = BSTCreate(7);
  Tree* r3 = BSTCreate(8);
  r1->left = l3;

  l2->left = l3;
  l2->right = r3;
  int sum = 0;
  leftLeafSum(root, sum);
  printf("%d\n", sum);
  return 0; 
}
