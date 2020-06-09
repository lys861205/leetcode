/*
 * 求所有根到叶子节点之和
*/

#include <stdio.h>
#include "Tree.h"

int res;

void dfs(Tree* root, int sum) 
{
  if (!root) return;
  sum = sum * 10 + root->value;
  if (root->left == nullptr && root->right == nullptr) {
    res += sum;
    return ;
  }
  dfs(root->left, sum);
  dfs(root->right, sum);
}

int sumNumbers(Tree* root)
{
  dfs(root, 0);
  return res;
}

int main()
{
  Tree* root = BSTCreate(1);
  Tree* l1 = BSTCreate(2);
  Tree* r1 = BSTCreate(3);
  root->left = l1;
  root->right = r1;
  // Tree* l2 = BSTCreate(12);
  // Tree* r2 = BSTCreate(13);
  // r1->left = l2;
  // r1->right = r2;
  //
  // Tree* l3 = BSTCreate(12);
  // Tree* r3 = BSTCreate(13);
  printf("%d\n", sumNumbers(root));
  return 0;
}
