#include <stdio.h>
#include "List.h"

Node* reserve_list(Node* head)
{
  Node* cur = head;
  Node* pre = NULL;
  while (cur) {
    Node* tmp = cur->next;
    cur->next = pre;
    pre = cur;
    cur = tmp;
  }
  return pre;
} 

int main()
{
  Node* head = NULL;
  for (int i=0; i < 10; ++i) {
    Node* l = Add(i);
    l->next = head;
    head = l;
  }
  Print(head);
  head = reserve_list(head);
  Print(head);
  return 0;
}



