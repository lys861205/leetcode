/*
 * 两两交换链表中节点
*/
#include <stdio.h>
#include "List.h"

Node* swapPairs(Node* head)
{
  if (!head || !head->next) {
    return head;
  }
  Node* p = head;
  Node* q = head->next;
  Node* l2 = q->next;
  q->next = p;
  p->next = swapPairs(l2);
  return q;
}

int main()
{
  Node* head = Add(0);
  Node* tmp = head;
  for (int i=1; i <= 10; ++i) {
    Node* node = Add(i);
    tmp->next = node;
    tmp = node;
  }
  Print(head);
  Node* h = swapPairs(head);
  Print(h);
  return 0;
}
