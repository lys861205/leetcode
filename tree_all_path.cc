/*
 * 257: 二叉树的所有路径
 */

#include <stdio.h>
#include "Tree.h"
#include <vector>

using namespace std;

void helper(Tree* root, vector<vector<int>>& paths,  vector<int>& path)
{
  if (!root) {
    return;
  }
  path.push_back(root->value);
  if (root->left == nullptr && root->right == nullptr) {
    paths.push_back(path);
  }
  if (root->left) {
    helper(root->left, paths, path);
  }
  if (root->right) {
    helper(root->right, paths, path);
  }
  path.pop_back();
}

vector<vector<int>> BinaryTreePaths(Tree* root)
{
  vector<vector<int>> r_paths;
  vector<int> path;
  helper(root, r_paths, path);
  return r_paths;
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
  vector<vector<int>> paths = BinaryTreePaths(root);
  for (int i = 0; i < paths.size(); ++i) {
    printf("[");
    for (int j = 0; j < paths[i].size(); ++j) {
      printf("%d ", paths[i][j]); 
    }
    printf("]\n");
  }
  return 0;
}
