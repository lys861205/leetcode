#include "Tree.h"
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

unordered_map<string, int> memo;

string Traverse(Tree* root, vector<Tree*>& res);

vector<Tree*> FindDuplicateSubTrees(Tree* root)
{
  vector<Tree*> res;
  Traverse(root, res);
  return std::move(res);
}

string Traverse(Tree* root, vector<Tree*>& res)
{
  if (nullptr == root) {
    return string("#");
  }
  string leftString = Traverse(root->left, res);
  string rightString = Traverse(root->right, res);
  string subtree = leftString + ',' + rightString + ',' + to_string(root->value);
  printf("%s\n", subtree.c_str());
  memo[subtree]++;
  if (memo[subtree] == 2) {
    res.push_back(root); 
  }
  return subtree;
}

int main()
{
  Tree* root = BSTCreate(1);
  {
   AddLeft(AddLeft(root, 2), 4);
  }
  {
    Tree* r = AddRight(root, 3);
    AddLeft(AddLeft(r, 2), 4);
    AddRight(r, 4);
  }
  Print(root, 3, '*');
  vector<Tree*> res = FindDuplicateSubTrees(root);
  for (int i=0; i < res.size(); ++i) {
    Print(res[i], 3, '*');
  }
  return 0;
}
