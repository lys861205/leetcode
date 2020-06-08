/*
 * 填充每个节点的下一个右侧节点指针
*/

#include <stdio.h>
#include "Tree.h"
#include <queue>

using namespace std;

void ConnectNode(Tree* root)
{
  if (!root) return ;
  queue<Tree*> qt;
  qt.push(root);
  while (!qt.empty()) {
    Tree* pre = NULL;
    int sz = qt.size();
    for (int i = 0; i < sz; ++i) {
      Tree* tr = qt.front();
      qt.pop();
      if (pre) {
        pre->next = tr;
      }
      if (tr->left) qt.push(tr->left);
      if (tr->right) qt.push(tr->right);
      pre = tr;
      tr = NULL;
    }
  }
}

int main()
{
  return 0;
}
