#include <stdio.h>
#include "Tree.h"
#include <stack>

using namespace std;


//前序遍历 迭代
void PrologueIterator(Tree* root)
{
  Tree* p = root;
  stack<Tree*> s;
  while (p || !s.empty()) {
    while (p) {
      s.push(p->right);
      printf("%d ", p->value);
      p = p->left;
    }
    p = s.top(); s.pop();
  }
  printf("\n");
}

//中续遍历 迭代
void FollowIterator(Tree* root)
{
  Tree* p = root;
  stack<Tree*> s;
  while (p || !s.empty()) {
    while (p) {
      s.push(p);
      p = p->left;
    }
    p = s.top(); s.pop();
    if (p) {
      printf("%d ", p->value);
      p = p->right;
    }
  }
  printf("\n");
}

int main()
{
  
  Tree* root = BSTCreate(10);
  Tree* l = AddLeft(root, 9);
  Tree* r = AddRight(root, 11);
  AddLeft(l, 5);
  AddRight(l, 6);
  AddLeft(r, 8);
  AddRight(r, 7);
  Print(root, 3, '*');
  PrologueIterator(root);
  FollowIterator(root);
  return 0;
}
