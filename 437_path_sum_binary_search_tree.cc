/*
 * 找出路径和等于给定数值的路径总数
*/
#include <stdio.h>
#include "Tree.h"

void dfs(Tree* root, int sum, int& count)
{
  if (!root) return;
  if (root->value == sum) {
    ++count;
  }
  dfs(root->left, sum-root->value, count);
  dfs(root->right, sum-root->value, count);
}

void countPath(Tree* root, int sum, int& count)
{
  if(!root) return;
  dfs(root, sum,  count);
  countPath(root->left, sum, count);
  countPath(root->right, sum, count);
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

  l2->left = l3;
  l2->right = r3;

  Print(root, 3, '*');
  int count = 0;
  countPath(root, 12, count);
  printf("%d\n", count);
  return 0;
}
