#include <stdlib.h>
#include <stdio.h>

struct Node {
  int value;
  Node* next;
};

Node* Add(int value)
{
  Node* node = (Node*)malloc(sizeof(Node));
  node->next = NULL;
  node->value = value;
  return node;
}

int Len(Node* node) 
{
  Node* p = node;
  int len = 0;
  while (p) {
    p = p->next;
    ++len;
  }
  return len;
}

void Print(Node* node)
{
  Node* p = node;
  while (p) {
    printf("%d->", p->value);
    p = p->next;
  }
  printf("NULL\n");
}
