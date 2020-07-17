/*
 * 返回倒数第K个节点
*/

#include "node.h"

Node* kthLast(Node* head, int k)
{
  Node* curr = head;
  for (int i=0; i < k && curr; ++i) {
    curr = curr->next;
  }
  if (!curr) {
    return nullptr;
  }
  Node* kth = head;
  while (curr) {
    kth = kth->next;
    curr = curr->next;
  }
  return kth;
}

int main()
{
  Node* head = new Node(1);
  for (int i=2; i < 10; ++i) {
    Insert(head, i);
  }
  Printf(head);
  Printf(kthLast(head, 4));
  return 0;
}
