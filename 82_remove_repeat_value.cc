/*
 * 删除排序链表中重复的元素
*/
#include <stdio.h>
#include "List.h"

Node* removeRepeatValue(Node* h)
{
  if (!h || !h->next) return h;
  Node* cur = h->next;
  Node* ppre = nullptr;
  Node* pre = h;
  Node* nh = nullptr;
  while (cur) {
    if (pre->value == cur->value) {
      pre->next = cur->next;
      cur = cur->next;
      if (!cur) {
        ppre->next = nullptr;
      }
    }
    else {
      ppre = pre;
      pre = cur;
      cur = cur->next;
      if (!nh) {
        nh = pre;
      }
    }
  }
  return nh;
}

int main()
{
  Node* h = Add(1);
  Node* l1 = Add(1);
  h->next = l1;
  Node* l2 = Add(2);
  l1->next = l2;
  Node* l3 = Add(3);
  l2->next = l3;
  Node* l4 = Add(3);
  l3->next = l4;
  Print(h);
  Print(removeRepeatValue(h));
  return 0;
}
