/*
 * 填充每个节点的下一个右侧节点指针
 * 描述:给定一个完美二叉树，其所有叶子节点都在同一层，
 * 每个父节点都有2个子节点
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
    pre->next = NULL;
  }
}

#include <unordered_map>

std::unordered_map<int, int> visited;

void NextTree(Tree* root, int lvl)
{
  if (!root) return;
  if (visited.count(lvl) > 0) {
    ++lvl;
    NextTree(root->left, lvl);
    NextTree(root->right, lvl);
    return;
  }
  Tree* t = root;
  while (t) {
    printf("%d ", t->value);
    t = t->next;
  }
  printf("\n");
  visited[lvl] = 1;
  ++lvl;
  NextTree(root->left, lvl);
  NextTree(root->right, lvl);
}

int main()
{
  Tree* root = BSTCreate(10);
  Tree* l1 = BSTCreate(9);
  Tree* r1 = BSTCreate(11);
  //root->left = l1;
  root->right = r1;

  Tree* l2 = BSTCreate(12);
  Tree* r2 = BSTCreate(13);
  r1->left = l2;
  r1->right = r2;

  Tree* l3 = BSTCreate(12);
  Tree* r3 = BSTCreate(13);

  r2->left = l3;
  r2->right = r3;
  Print(root, 3, '*');
  ConnectNode(root);
  NextTree(root, 0);
  return 0;
}
