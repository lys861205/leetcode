/*
 * 二叉搜索树最近公共祖先
*/

#include <stdio.h>
#include "Tree.h"
#include <stack>

using namespace std;

bool Match(Tree* root, Tree* p, stack<Tree*>& st)
{
  if (!root) return false;
  if (root == p) return true;
  st.push(root);
  if (Match(root->left, p)) {
    return true;  
  }
  st.pop(root);
  if (Match(root->right, p)) {
    return true;
  }
  st.pop(root);
  return false;
}

Tree* lowestCommonParent(Tree* root, Tree* p, Tree* q)
{
  if (!root) return NULL;
  if (root == p || root == q) return root;
  Tree* l_parent = lowestCommonParent(root->left, p, q);
  Tree* r_parent = lowestCommonParent(root->right, p, q);
  if (l_parent != NULL && r_parent != NULL) {
    return root;
  }
  else if (l_parent != NULL) {
    return l_parent;
  }
  else if (r_parent != NULL) {
    return r_parent;
  }
}
