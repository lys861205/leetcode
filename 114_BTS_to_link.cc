#include <stdio.h>
#include <stack>
#include "Tree.h"

using namespace std;

void BTSToLink(Tree*& root, stack<Tree*>& st, int level)
{
  if (!root) return;
  BTSToLink(root->right, st, level+1);
  st.push(root);
  BTSToLink(root->left, st, level+1);
  if (level==0) {
    root = st.top();
    st.pop();
    Tree* prev = root;
    while (!st.empty()) {
      Tree* cur = st.top(); 
      st.pop();
      if (prev) {
        prev->right = cur;
        cur->left = prev;
      }
      prev = cur;
    }
  }
}

int main()
{
  stack<Tree*> st;
  Tree* root = BSTCreate(5); 
  root = BSTAdd(root, 4);
  root = BSTAdd(root, 6);
  BTSToLink(root, st, 0);
  
  while(root) {
    printf("%d ", root->value); 
    root = root->right;
  }
  return 0;
}
