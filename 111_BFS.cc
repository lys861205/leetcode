#include <stdio.h>
#include <queue>
#include "Tree.h"

using namespace std;

int minDepth(Tree* root) 
{
  if (root == NULL) {
    return 0;
  }
  queue<Tree*> q;
  q.push(root);
  int depth = 1;
  while (!q.empty()) {
    int sz = q.size();
    for (int i=0; i < sz; ++i) {
      Tree* node = q.front();
      q.pop();
      if (node->left == NULL && node->right == NULL) {
        return depth;
      }
      if (node->left != NULL) {
        q.push(node->left); 
      }
      if (node->right != NULL) {
        q.push(node->right); 
      }
    }

    ++depth;
  }
  return depth;
}

int main()
{
  Tree* root = BSTCreate(5);
  BSTAdd(root, 1);
  BSTAdd(root, 4);
  BSTAdd(root, 3);
  BSTAdd(root, 2);
  BSTAdd(root, 6);
  BSTAdd(root, 7);
  BSTAdd(root, 8);
  printf("minDepth: %d\n", minDepth(root));
  return 0;
}
