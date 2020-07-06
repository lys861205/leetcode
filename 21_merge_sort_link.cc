/*
 * 合并2个有序链表
*/
#include <stdio.h>
#include "List.h"

Node* mergeSortedList(Node* h1, Node* h2)
{
  if (!h1) return h2;
  if (!h2) return h1;
  Node* p = h1;
  Node* pre = h1;
  Node* q = h2;
  while (p && q) 
  {
    if (q->value < p->value) {
      pre->next = q;
      pre = q;
      q = q->next;
    } else {
      if (pre != p) {
        pre->next =  p;
      }
      pre =  p;
      p = p->next;
    }
  }
  if (p) {
    pre->next = p;
  }
  if (q) {
    pre->next = q;
  }
  return h1;
}

int main()
{
  Node* h1 = Add(1); 
  Node* t1 = h1;
  {
    // Node* l1 = Add(2);
    // Node* l2 = Add(4);
    // h1->next = l1;
    // l1->next = l2;
  }

  Node* h2 = Add(1); 
  Node* t2 = h2;
  {
    // Node* l1 = Add(3);
    // Node* l2 = Add(4);
    // h2->next = l1;
    // l1->next = l2;
  }
  for (int i = 2; i < 10; ++i) {
    Node* l1 = Add(i); 
    Node* l2 = Add(i+1); 
    t1->next = l1;
    t2->next = l2;
    t1 = l1;
    t2 = l2;
  }
  Print(mergeSortedList(h1, h2));
  return 0;
}
