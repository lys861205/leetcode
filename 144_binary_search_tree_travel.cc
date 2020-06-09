/*
 * 二叉树的前序遍历
*/

#include <stdio.h>
#include "Tree.h"
#include <vector>
#include <stack>

using namespace std;

vector<int> IteratorTravelTree(Tree* root)
{
  vector<int> res;
  if (!root) return res;
  stack<Tree*> st;
  Tree* t = root;
  while (t || !st.empty()) 
  {
    if (t) {
      res.emplace_back(t->value);
      st.push(t);
      t = t->left;
    }else {
      t = st.top(); 
      st.pop();
      t = t->right;
    }
  }
  return res;
}

void PreTravelTree(Tree* root, vector<int>& res)
{
  if (!root) return;
  res.push_back(root->value);
  PreTravelTree(root->left, res);
  PreTravelTree(root->right, res);
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

  vector<int> res;
  res = IteratorTravelTree(root);
  //PreTravelTree(root, res);
  printf("[");
  for (size_t i=0; i < res.size(); ++i) {
    printf("%d ", res[i]);
  }
  printf("]\n");
  return 0;
}


