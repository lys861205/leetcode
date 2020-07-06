/*
 * 相交链表，相交点节点
*/
#include <stdio.h>
#include "List.h"

Node* GetIntersectionNode(Node* headA, Node* headB)
{
  Node* p = headA;
  Node* q = headB;
  int cnt = 0;
  while (p != q) {
    p = (p==nullptr) ? headB : p->next;
    q = (q==nullptr) ? headA : q->next;
  }
  return p;
}

int main()
{
  Node* headA = Add(1);
  Node* l1 = Add(2);
  Node* l2 = Add(3);
  Node* l3 = Add(4);
  Node* l4 = Add(5);
  Node* l5 = Add(6);
  headA->next = l1;
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l5;

  Node* headB = Add(7);
  Node* l6 = Add(8);
  headB->next = l6;
  l6->next = l3;
  Node* n = GetIntersectionNode(headA, headB);
  if (n == nullptr) {
    printf("no intersect node\n");
  } else {
    printf("%d\n", n->value);
  }
  return 0;
}
