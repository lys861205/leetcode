/*
 * 重排链表
*/

#include <stdio.h>
#include "List.h"

Node* reorderList(Node* h)
{
  if (!h || !h->next) return h;
  Node* p = h;
  Node* pre = p;
  while (p->next) {
    pre = p;
    p = p->next;
  }
  pre->next = nullptr;
  p->next = reorderList(h->next);
  h->next = p;
  return h;
}


int main()
{
  Node* h = Add(1); 
  Node* p = h;
  for (int i=2; i < 6;++i) {
    Node* l = Add(i);
    p->next = l;
    p = l;
  }
  Print(h);
  Print(reorderList(h));
  return 0;
}
