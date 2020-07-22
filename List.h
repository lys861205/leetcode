#include <stdlib.h>
#include <stdio.h>

struct Node {
  int value;
  Node* next;
  Node():next(nullptr){}
  Node(int value):value(value),next(nullptr){}
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

Node* Tail(Node* head)
{
  Node* cur = head;
  Node* tail = nullptr;
  while (cur) {
    tail = cur;
    cur = cur->next;
  }
  return tail;
}

void Insert(Node* &head, int value)
{
  Node* n = new Node(value);
  n->next = head;
  head = n;
}

void InsertTail(Node* &head, int value) 
{
  if (!head) {
    head = new Node(value);
    return;
  }
  Node* curr = head;
  Node* prev = nullptr;
  while (curr) {
    prev = curr;
    curr = curr->next;     
  }
  prev->next = new Node(value);
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
