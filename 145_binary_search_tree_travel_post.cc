/*
 * 二叉树后序遍历
*/

#include <stdio.h>
#include "Tree.h"
#include <vector>
#include <stack>

using namespace std;


vector<int> PostIterateTree(Tree* root)
{
  vector<int> res;
  Tree* p = root;
  stack<Tree*> st;
  while (p || !st.empty()) {
    if (p) {
      st.push(p);
      p = p->left;
    } else {
      p = st.top();
      if (p->right) {
        p = p->right; 
        st.push(p);
      } else {
        res.push_back(p->value);
        st.pop();
      }
    }
  }
  return res;
}

int main()
{
  return 0;
}



