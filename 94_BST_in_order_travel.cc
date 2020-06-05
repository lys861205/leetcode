#include <stdio.h>
#include "Tree.h"
#include <stack>

using namespace std;

void Travel(Tree* root) {
  if (!root) return;
  Travel(root->left);
  printf("%d ", root->value);
  Travel(root->right);
}

//前序遍历 迭代
void PreOrderTraversal(Tree* root) {
  stack<Tree*> s;
  Tree* p = root;
  while (p || !s.empty()) {
    while (p) {
      s.push(p->right);
      printf("%d ", p->value);
      p = p->left;
    }
    p = s.top(); s.pop();
  }
}

//后序遍历 迭代
void PostOrderTraversal(Tree* root) {
  stack<Tree*> s;
  Tree* p = root;
  while (p || !s.empty()) {
    while (p) {
      s.push(p);
      printf("%d ", p->value);
      p = p->left;
    }
    p = s.top(); s.pop();
  }
}

int main()
{
  Tree* root = BSTCreate(2);
  root = BSTAdd(root, 4);
  root = BSTAdd(root, 1);
  Travel(root);
  printf("\n");
  PreOrderTraversal(root);
  printf("\n");
  return 0;
}
