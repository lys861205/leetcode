#include <stdio.h>

struct Node {
  int value = 0;
  Node* next = nullptr;
  Node(int data):value(data), next(nullptr){}
};

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

void Printf(Node* head)
{
  if (!head) {
    printf("NULL\n");
    return;
  }
  printf("%d->", head->value);
  Printf(head->next);
}

void Iterator(Node* head)
{
  Node* cur = head;
  while (cur) {
    printf("%d->", cur->value);
    cur = cur->next;
  }
  printf("NULL\n");
}
