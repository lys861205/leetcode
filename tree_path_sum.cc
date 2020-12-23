#include <stdio.h>
#include "Tree.h"
#include <vector>

using namespace std;


bool hasPathSum(Tree* root, int sum)
{
  if (root == nullptr && sum == 0) {
    return true;
  }
  if (root == nullptr) {
    return false;
  }
  sum -= root->value;
  return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}

vector<vector<int> > g_paths;

void PathSum(Tree* root, int sum, vector<int>& path)
{
  if (root == nullptr) {
    return;
  }
  path.push_back(root->value);
  sum -= root->value;
  if (!root->left && !root->right && sum == 0) {
      g_paths.push_back(path);
      return;
  }
  PathSum(root->left, sum, path);
  PathSum(root->right, sum, path);
  path.pop_back();
}

void GetPathSum(Tree* root, int sum) 
{
  vector<int> path;
  PathSum(root, sum, path);
}

int main()
{
  
  Tree* root = BSTCreate(5);
  Tree* ll = AddLeft(AddLeft(root, 4), 11);
  AddLeft(ll, 7);
  AddRight(ll, 2);
  Tree* rr= AddRight(root, 8);
  AddLeft(rr, 13);
  AddRight(AddRight(rr, 4), 1);
  Print(root, 3, '*');
  printf("%s\n", hasPathSum(root, 22) ? "True" : "False");
  GetPathSum(root, 22);
  for (int i = 0; i < g_paths.size(); i++) {
    printf("{");
    for (int j = 0; j < g_paths[i].size(); ++j) {
      printf("%d ", g_paths[i][j]); 
    }
    printf("}\n");
  }
  return 0;
}
