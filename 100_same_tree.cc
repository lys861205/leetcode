/*
 * 相同的树
*/
#include <stdio.h>
#include "Tree.h"


bool IsSameTree(Tree* tr1, Tree* tr2) 
{
  if (NULL == tr1 && NULL == tr2) return true;
  if (!tr1 || !tr2) return false;
  if (tr1->value != tr2->value) return false;
  if (!IsSameTree(tr1->left, tr2->left)) {
    return false;
  }
  if (!IsSameTree(tr1->right, tr2->right)) {
    return false;
  }
  return true;
}

int main()
{
  Tree* tr1 = BSTCreate(4);  
  BSTAdd(tr1, 3);
  BSTAdd(tr1, 5);

  Tree* tr2 = BSTCreate(4);  
  BSTAdd(tr2, 5);
  BSTAdd(tr2, 3);
  BSTAdd(tr2, 2);
  printf("%d\n", IsSameTree(tr1, tr2));
  return 0;
}


