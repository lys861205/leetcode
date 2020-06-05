/*
 * 不同二叉搜索树
*/

#include <stdio.h>
#include "Tree.h"
#include <vector>

using namespace std;

vector<Tree*> BuildTrees(int start, int n)
{
  vector<Tree*> res;
  if (start > n) {
    res.push_back(NULL);
  }
  
  for (int i=start; i<=n; ++i) {
    vector<Tree*> ls = BuildTrees(start, i-1); 
    vector<Tree*> rs = BuildTrees(i+1, n); 
    for (auto l:ls) {
      for (auto r:rs) {
        Tree* root = BSTCreate(i);
        root->left = l;
        root->right = r;
        res.push_back(root);
      }
    }
  }
  return res;
}

void Travel(Tree* root) {
  //前序遍历
  if (!root) return;
  printf("%d ", root->value);
  Travel(root->left);
  Travel(root->right);
}

int main()
{
  vector<Tree*> res = BuildTrees(1, 8);
  for (size_t i=0; i < res.size(); ++i) {
    printf("{");
    Travel(res[i]);
    printf("}\n");
  }
  return 0;
}


