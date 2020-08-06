/*
 * 2链表相加
*/

#include <stdio.h>
#include "List.h"

Node* ListAddList(Node* head1, Node* head2)
{
  int carry = 0;
  Node* p = head1;
  Node* q = head2;
  Node dummy;
  Node* cur = &dummy;
  while (p || q || carry) {
    int sum = 0;
    if (p && q) {
      sum = p->value + q->value + carry;
      p = p->next;
      q = q->next;
    } 
    else if (p) {
      sum = p->value + carry;
      p = p->next;
    }
    else if (q) {
      sum = q->value + carry;
      q = q->next;
    }
    else {
      sum = carry;
    }
    carry = sum / 10;
    sum %= 10;
    Node* node = Add(sum);
    cur->next = node;
    cur = node;
  }
  return dummy.next;
}
int main()
{
  Node *head1 = Add(2);
  {
    Node* l1 = Add(4);
    Node* l2 = Add(3);
    head1->next = l1;
    l1->next = l2;
  }
  Node *head2 = Add(5);
  {
    Node* l1 = Add(6);
    Node* l2 = Add(4);
    head2->next = l1;
    l1->next = l2;
  }
  Node* sum_node = ListAddList(head1, head2);
  Print(sum_node);
  return 0;
}
