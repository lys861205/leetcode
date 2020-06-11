/*
 * 二叉搜索树最小绝对值
*/

#include <stdio.h>
#include "Tree.h"
#include <cmath>
#include <algorithm>

using namespace std;

int getMinAbs(Tree* root)
{
  int diff = 0x7fffffff;
  if (!root) return diff;
  if (root->left)  {
    Tree* l = root->left;
    diff = min(abs(l->value - root->value), diff);
  }
  if (root->right)  {
    Tree* r = root->right;
    diff = min(abs(r->value - root->value), diff);
  }
  diff = min(getMinAbs(root->left), diff);
  diff = min(getMinAbs(root->right), diff);
  return diff;
}

int main()
{
  Tree* root = BSTCreate(1);
  Tree* l1 = BSTCreate(10);
  Tree* r1 = BSTCreate(8);
  root->right = r1;
  r1->right = l1;
  Print(root, 3, '*');
  printf("%d\n", getMinAbs(root));
  return 0;
}
