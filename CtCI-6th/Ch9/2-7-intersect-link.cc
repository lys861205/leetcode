/*
 * 2链表相加点
*/

#include "node.h"

Node* Intersection(Node* p, Node* q)
{
  Node* pp = p;
  Node* qq = q;
  while (pp != qq) {
    pp = (pp->next)? pp->next : q;
    qq = (qq->next)? qq->next : p;
  }
  return qq;
}

int main()
{
  Node* crosspoint = new Node(100);
  Node* p = nullptr;
  for (int i=0; i < 10; i++) {
    Insert(p, i); 
    if (i==5) {
      crosspoint->next = p;
      p = crosspoint;
    }
  }
  Node *q = nullptr;
  for (int i=0; i < 2; ++i) {
    Insert(q, i); 
  }
  Tail(q)->next = crosspoint;
  Printf(q);
  Printf(p);
  Printf(Intersection(p, q));
  return 0;
}
