#include "List.h"

Node* mergeSortedLink(Node* h1, Node* h2)
{
  Node dummy;
  Node* cur = &dummy;
  Node* p = h1;
  Node* q = h2;
  while (p && q) {
    if (p->value < q->value) {
      cur->next = p;
      p = p->next;
    }
    else {
      cur->next = q;
      q = q->next;
    }
    cur = cur->next;
  }
  while (p) {
    cur->next = p;
    p = p->next;
    cur = cur->next;
  }
  while (q) {
    cur->next = q;
    q = q->next;
    cur = cur->next;
  }
  return dummy.next;
}

int main()
{
  Node dummy1;
  Node* cur = &dummy1;
  for (int i=0; i < 10; i +=2) {
    cur = Append(cur, i);
  }
  Printf(dummy1.next);
  Node dummy2;
  cur = &dummy2;
  for (int i=1; i < 10; i +=2) {
    cur = Append(cur, i);
  }
  Printf(dummy2.next);

  Printf(mergeSortedLink(dummy1.next, dummy2.next));
  return 0;
}
