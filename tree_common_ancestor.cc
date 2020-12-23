/*
 * 235: 二叉搜索树最近公共祖先
 * 236: 二叉树最近公共祖先
*/

#include <stdio.h>
#include "Tree.h"



Tree* SearchTreeOfCommonAncestor(Tree* root, Tree* p, Tree* q)
{
  if (!root) return nullptr;  
  if (root == p || root == q) {
    return root;
  }
  Tree* l = SearchTreeOfCommonAncestor(root->left, p, q);
  Tree* r = SearchTreeOfCommonAncestor(root->right, p, q);
  if (l && r) {
    return root; 
  }
  return l ? l : r;
}

Tree* TreeOfCommonAncestor(Tree* root, Tree* p, Tree* q)
{
  if (!root) return nullptr;  
  if (root == p || root == q) {
    return root;
  }
  Tree* l = TreeOfCommonAncestor(root->left, p, q);
  Tree* r = TreeOfCommonAncestor(root->right, p, q);
  if (l && r) {
    return root; 
  }
  return l ? l : r;
}



int main()
{
  Tree* root = BSTCreate(5);
  Tree* ll = AddLeft(AddLeft(root, 4), 11);
  Tree* _7l = AddLeft(ll, 7);
  Tree* _2r = AddRight(ll, 2);
  Tree* rr= AddRight(root, 8);
  AddLeft(rr, 13);
  AddRight(AddRight(rr, 4), 1);
  Print(root, 3, '*');
  Tree* ancestor = SearchTreeOfCommonAncestor(root, _7l, _2r);
  printf("%d\n", ancestor->value);
  ancestor = TreeOfCommonAncestor(root, _7l, _2r);
  printf("%d\n", ancestor->value);
  return 0;
}
