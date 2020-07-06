/*
 * 旋转链表
*/

#include <stdio.h>
#include "List.h"

Node* rotateRight(Node* head, int k)
{
  int length = Len(head);
  k %= length;
  if (!k) {
    return head;
  }
  k = length - k;
  Node* p = head;
  for (int _=1; _ < k; ++_) {
    p = p->next; 
  }
  Node* q = p->next;
  p->next = NULL;
  Node* tail = q;
  while (tail->next) {
    tail = tail->next;
  }
  tail->next = head;
  return q;
}

int main()
{
  Node* h = Add(1);
  Node* tmp = h;
  for (int i=2; i < 6; ++i) {
    Node* l = Add(i);
    tmp->next = l;
    tmp = l;
  }
  Print(h);
  Node* h2 = rotateRight(h, 4);
  Print(h2);
  return 0;
}
