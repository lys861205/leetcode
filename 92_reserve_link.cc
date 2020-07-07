/*
 * 反转链表(m,n)
*/

#include <stdio.h>
#include "List.h"

Node* reverse(Node* h){
  if (!h) return h;
  Node* pre = nullptr;
  Node* cur = h;
  while (cur) {
    Node* tmp = cur->next;
    cur->next = pre;
    pre = cur;
    cur = tmp;
  }
  return pre;
}

Node* reverseBetween(Node* h, int m, int n)
{
  if (m >=n ) {
    return h;
  }
  Node* p = h;
  Node* pre = nullptr;
  Node* pre_start = nullptr;
  Node* start = nullptr;
  Node* end = nullptr;
  for (int i=1; i <= n && p; ++i) {
      if (i==m) {
        pre_start = pre; 
        start = p;  
      }
      if (i==n) {
        end = p;
      }
      pre = p;
      p = p->next;
  }
  if (!end || !start) {
    return h;
  }
  Node* tail = end->next;
  end->next = nullptr;
  pre_start->next = reverse(start); 
  start->next = tail;
  return h;
}

int main()
{
  Node* h = Add(1);
  Node* p = h;
  for (int i=2; i < 6; ++i) {
    Node* l = Add(i);
    p->next = l;
    p = l;
  }
  Print(h);
  Print(reverseBetween(h, 2, 4));
  return 0;
}
