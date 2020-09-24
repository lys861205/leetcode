/*
 * 二叉树的所有路径
*/

#include <stdio.h>
#include "Tree.h"
#include <vector>

using namespace std;

vector<vector<int> > paths;



void AllPath(Tree* root, vector<int>& path)
{
  if (!root) return;  
  path.push_back(root->value);
  if (root->left == NULL && root->right == NULL) {
    paths.emplace_back(path);
    return;
  }
  AllPath(root->left, path);
  path.pop_back();
  AllPath(root->right, path);
  path.pop_back();
}

void searchPath(Tree* root, vector<int> path)
{
  if (!root) return;
  path.push_back(root->value);
  if (NULL == root->left && NULL == root->right) {
    paths.push_back(path);
    return;
  }
  searchPath(root->left, path);
  searchPath(root->right, path);
  //path.pop_back();
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

  vector<int> path; 
  //AllPath(root, path);
  searchPath(root, path);
  for (size_t i=0; i < paths.size(); ++i) {
    printf("[");
    for (size_t j=0; j < paths[i].size(); ++j){
      printf("%d ", paths[i][j]); 
    }
    printf("]\n");
  }
  return 0;
}
