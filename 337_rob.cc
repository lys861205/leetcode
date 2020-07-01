/*
 * 打家劫舍3
*/
#include <stdio.h>
#include "Tree.h"
#include <algorithm>

int rob(Tree* root)
{
  if (!root) return 0;
  int do_it = root->value + (root->left == NULL ? 0 
                            : rob(root->left->left) + rob(root->left->right)) +
                            (root->right == NULL ? 0
                            : rob(root->right->left)+ rob(root->right->right));
  int not_do = rob(root->left) + rob(root->right);
  return max(do_it, not_do);
}

int main()
{
  Tree* root = BSTCreate(1);
  Tree* l1 = BSTCreate(2);
  Tree* r1 = BSTCreate(3);
  root->left = l1;
  root->right = r1;
  Tree* l2 = BSTCreate(4);
  Tree* r2 = BSTCreate(5);
  l1->left = l2;
  l1->right = r2;
  Tree* l3 = BSTCreate(6);
  Tree* r3 = BSTCreate(7);
  r1->left = l3;
  r1->right = r3;
  Print(root, 3, '*');
  printf("%d\n", rob(root));
  return 0;
}
