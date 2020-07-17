/*
 * 删除链表重复的元素
*/

#include "node.h"
#include <stdio.h>

void removeDuplicates(Node* head) 
{
  if (!head) {
    return;
  }
  if (!head->next) {
    return;
  }
  Node* cur = head;
  while (cur) {
    Node* runner = cur;
    while (runner && runner->next) {
      if (cur->value == runner->next->value) {
        runner->next = runner->next->next;
      } else {
        runner = runner->next;
      }
    }
    cur = cur->next;
  }
}

int main()
{
  Node* head = new Node(10);
  for (int i=9; i > 0; --i) {
    Insert(head, i);
  }
  Insert(head, 2);
  Insert(head, 3);
  Insert(head, 4);
  Printf(head);
  removeDuplicates(head);
  Printf(head);
  return 0;
}
