/*
 * 02.04 分割链表
*/

#include <stdio.h>
#include "List.h"

Node* splitNode(Node* h, int v)
{
  if (!h) return h; 
  Node* newhead = nullptr;
  Node* attach = h;
  Node* cur = h;
  Node* pre = nullptr;
  while (cur) {
    if (cur->value < v) {
      if (!attach) {
        attach->next = cur;
      }
      attach = cur;
    }
    if (!newhead) {
      newhead = cur;
    }
    pre = cur;
    cur = cur->next;
  }
}
int main()
{
  return 0;
}
