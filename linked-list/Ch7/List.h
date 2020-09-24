#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
  int value;
  LinkNode* next;
}Node;

Node* New(int value)
{
  Node* l = (Node*)malloc(sizeof(Node));
  if (l) {
    l->value = value;
    l->next = nullptr;
  }
  return l;
}

Node* Append(Node* l, int value)
{
  if (l) {
    l->next = New(value);
    return l->next;
  }
  return nullptr;
}

void Printf(Node* l)
{
  Node* p = l;
  while (p) {
    printf("%d->", p->value);
    p = p->next;
  }
  printf("NULL\n");
}

