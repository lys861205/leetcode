/*
 * 二叉树的增删查
*/

#include <stdio.h>
#include "Tree.h"

bool isValidTree(Tree* root, int min, int max)
{
  if (!root) return true;
  if ( (root->value < min) || (root->value > max) ) {
    return false;
  }
  return isValidTree(root->left, min, root->value) && isValidTree(root->right, root->value, max);
}

bool isInBST(Tree* root, int target)
{
  if (!root) return false;
  if (root->value == target) return true;
  if (root->value > target) {
    return isInBST(root->left, target);
  }
  else if (root->value < target) {
    return isInBST(root->right, target);
  }
}

Tree* insertIntoBST(Tree* root, int value)
{
  if (!root) {
    root = BSTCreate(value);
    return root;
  }
  if (root->value > value) {
    root->left = insertIntoBST(root->left, value);
  }
  else if (root->value < value) {
    root->right = insertIntoBST(root->right, value);
  }
  return root;
}

Tree* getMin(Tree* root)
{
  while (root) {
    root = root->left;
  }
  return root;
}

Tree* deleteNode(Tree* root, int value)
{
  if (!root) {
    return root;
  }
  if (root->value == value) {
    if (root->left == NULL && root->right == NULL) {
      return NULL;
    }
    else if (root->left==NULL) return root->right;
    else if (root->right==NULL) return root->left;
    else {
      Tree* t = getMin(root->right);
      root->value = t->value;
      root->right = deleteNode(root->right, t->value);
    }
  }
  else if (root->value < value) {
    root->right = deleteNode(root->right, value);
  }
  else if (root->value > value) {
    root->left = deleteNode(root->left, value);
  }
  return root;
}

int main()
{
  return 0;
}
