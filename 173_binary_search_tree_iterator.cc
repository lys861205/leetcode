/*
 * 二叉搜索树迭代器
*/
#include <stdio.h>
#include "Tree.h"
#include <stack>

using namespace std;

class BSTIterator {
public:
  BSTIterator(Tree* root)
  {
    Tree* p = root;
    while (p) {
      st_.push(p);
      p = p->left;
    }
  }

  int next() 
  {
    Tree* p = st_.top();
    st_.pop();
    Tree* r = p->right;
    while (r) {
      st_.push(r);
      r = r->left;
    }
    return p->value;
  }

  bool hasNext()
  {
    return !st_.empty();
  }
private:
  stack<Tree*> st_;
};

int main()
{
  Tree* root = BSTCreate(2);
  Tree* l1 = BSTCreate(1);
  Tree* r1 = BSTCreate(5);
  root->left = l1;
  root->right = r1;

  Tree* l2 = BSTCreate(3);
  Tree* r2 = BSTCreate(6);
  r1->left = l2;
  r1->right = r2;

  BSTIterator iter(root);
  printf("[");
  while (iter.hasNext()) {
    printf("%d ", iter.next());
  }
  printf("]\n");
  return 0;
}
