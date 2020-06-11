/*
 *  二叉树中找到出现最多的数字
*/

#include <stdio.h>
#include "Tree.h"

int number = -1;
int max_cnt = 0;
void findNode(Tree* root, int& cnt)
{
  findNode(root->left, cnt);
  if (number == root->value) {
      cnt++; 
  } else if (max_cnt < cnt) {
    max_cnt = cnt;
    cnt = 1;
  }
  findNode(root->right, cnt);
}

int main()
{
  Tree* root = BSTCreate(1);
  Tree* l1 = BSTCreate(2);
  Tree* r1 = BSTCreate(2);
  root->left = l1;
  root->right = r1;
  Tree* l2 = BSTCreate(2);
  Tree* r2 = BSTCreate(2);
  l1->left = l2;
  l1->right = r2;
  Tree* l3 = BSTCreate(6);
  Tree* r3 = BSTCreate(7);
  r1->left = l3;
  r1->right = r3;
  Print(root, 3, '*');
  int cnt = 0;
  findNode(root, cnt);
}
