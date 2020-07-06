/*
 * 奇偶链表
*/

#include <stdio.h>
#include "List.h"

Node* OddEvenNode(Node* head)
{
  if (!head || !head->next) return head;
  Node* odd = head;       // 奇数节点
  Node* even = head->next;// 偶数节点
  Node* even_header = even;
  while (odd->next && even->next) 
  {
    odd->next = odd->next->next;
    even->next = even->next->next;
    odd = odd->next;
    even = even->next;
  }
  odd->next = even_header;
  return head;
}

int main()
{
  Node* head = Add(1);
  Node* p = head;
  for (int i=2; i < 10; ++i) {
    Node* node = Add(i);
    p->next = node;
    p = node;
  }
  Print(head);
  head = OddEvenNode(head);
  Print(head);
  return 0;
}
