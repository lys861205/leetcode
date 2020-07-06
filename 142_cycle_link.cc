/*
 * 环形链表
*/
#include <stdio.h>
#include "List.h"

Node* entryNode(Node* head)
{
  Node* fast = head;
  Node* slow = head;
  Node* coincide = nullptr;
  while (slow && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      coincide = slow;
      break;
    }
  }
  Node* p = head;
  while (p && coincide) {
    if (p == coincide) {
      return p;
    }
    p = p->next;
    coincide = coincide->next;
  }
  return nullptr;
}

int main()
{
  Node* head = Add(1);
  Node* l1 = Add(2);
  Node* l2 = Add(3);
  Node* l3 = Add(4);
  Node* l4 = Add(5);
  Node* l5 = Add(6);
  head->next = l1;
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l5;
  l5->next = head;
  Node* cycle_entry = entryNode(head);
  if (nullptr != cycle_entry) {
    printf("%d\n", cycle_entry->value);
  }
  return 0;
}

