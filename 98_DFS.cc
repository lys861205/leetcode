#include <stdio.h>
#include <stack>
#include "Tree.h"

using namespace std;

bool IsValidBST(Tree* root)
{
  if (NULL == root) {
    return true;
  }
  stack<Tree*> St;
  St.push(root);
  while(!St.empty()) {
    Tree* node = St.top();
    St.pop();
    if (node->value)
    if (node->left) {
      St.push(node->left);
    }
    if (node->right) {
      St.push(node->right);
    }
  }
}

bool IsValidBST2(Tree* root, int lower, int upper)
{
  if (NULL == root) {
    return true;
  }
  if (root->value <= lower || root->value >= upper) {
    return false;
  }
  if (!IsValidBST2(root->left, lower, root->value)) {
    return false;
  }
  if (!IsValidBST2(root->right, root->value, upper)) {
    return false;
  }
  return true;
}

int main()
{
  int max = 0x7fffffff;
  int min = 0x80000000;
  Tree* root = BSTCreate(5);
  BSTAdd(root, 1);
  BSTAdd(root, 4);
  BSTAdd(root, 3);
  BSTAdd(root, 6);
  Print(root);
  printf("\n");
  printf("%d\n", IsValidBST2(root, min, max));
  return 0;
}
