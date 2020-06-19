#include <stdio.h>
#include "List.h"


int GetDecimalValue(Node* head)
{
  int ans = 0;
  Node* node = head;
  while (node) {
    ans = ans*2 + node->value;
    node = node->next;
  }
  return ans;
}

int main()
{
  Node* head = Add(1);
  Node* node = Add(0);
  Node* node1 = Add(1);
  head->next = node;
  node->next = node1;
  printf("%d\n", GetDecimalValue(head));
  return 0;
}
