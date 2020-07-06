/*
 * 删除链表倒数第n个节点
*/

#include <stdio.h>
#include "List.h"

Node* removeNthNode(Node* head, int n)
{
  Node* p = head;
  for (int i=0; i < n && p; ++i)
  {
    p = p->next; 
  }
  if (p == NULL) {
    return head;
  }
  Node* q = head;
  Node* pre;
  while (p) {
    p = p->next;
    pre = q;
    q = q->next;
  }
  pre->next = q->next;
  return head;
}

int main()
{
  Node* head = Add(1);
  Node* move = head;
  for (int i=2; i < 10; ++i) {
    Node* l = Add(i);
    move->next = l;
    move = l;
  }
  Print(head);
  head = removeNthNode(head, 1);
  Print(head);
  return 0;
}
