/*
 * 二叉树路径总和
*/
#include <stdio.h>
#include "Tree.h"
#include <vector>
#include <stack>

using namespace std;

vector<vector<int> > res;
vector<int> path;

void pathSum(Tree* root, int target) 
{
  if (!root) {
    return;
  }
  path.push_back(root->value);
  int sum = target - root->value;
  if (NULL == root->left && NULL == root->right && sum==0)
  { 
    res.push_back(path);
  }
  pathSum(root->left, sum);
  pathSum(root->right, sum);
  path.pop_back();
}

int main()
{
  Tree* root = BSTCreate(5); 
  {
    
    Tree* l1 = AddLeft(root, 4);
    Tree* r1 = AddRight(root, 8);
    l1 = AddLeft(l1, 11);
    AddLeft(r1, 13);
    r1 = AddRight(r1, 4);
    AddLeft(l1, 7);
    AddRight(l1, 2);
    AddLeft(r1, 5);
    AddRight(r1, 1);
  }
  Print(root, 3, '*');
  pathSum(root, 22);
  for (int i=0; i < res.size(); ++i) {
    printf("[");
    for (int j=0; j < res[i].size(); ++j) {
      printf("%d ", res[i][j]);
    }
    printf("]\n");
  }
  return 0;
}

