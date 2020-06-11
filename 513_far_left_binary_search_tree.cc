/*
 * 给定一个二叉树，在树的最后一行找到最左的值
 **/
 #include <stdio.h>
 #include "Tree.h"
 #include <queue>

 using namespace std;


int findBottomLeft(Tree* root)
{
  queue<Tree*> qt;
  if (!root) return -1;
  qt.push(root);
  Tree* t;
  while (!qt.empty()) {
    t  = qt.front();
    qt.pop();
    if (t->right) qt.push(t->right);
    if (t->left) qt.push(t->left);
  }
  return t->value;
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
  printf("%d\n", findBottomLeft(root));
  return 0;
}

