#include "List.h"
#include <stdio.h>

void deleteNode(Node*& head, Node* node)
{
  if (!head || !node) {
    return ;
  }
  Node* pre = NULL;
  Node* cur = head;
  while (cur) {
    if (cur == node) {
      if (pre == NULL) {
        head = node->next;
      } else {
        pre->next = node->next;
      }
      break;
    }
    pre = cur;
    cur = cur->next;
  }
}

int main()
{
  Node* head = Add(4); 
  Node* node1 = Add(5); 
  Node* node2 = Add(1); 
  Node* node3 = Add(9); 
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  Print(head);
  deleteNode(head, NULL);
  Print(head);
  deleteNode(head, head);
  Print(head);
  deleteNode(head, node1);
  Print(head);
  deleteNode(head, node2);
  Print(head);
  return 0;
}
