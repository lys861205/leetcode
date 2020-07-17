/*
 * 分割链表pivot
*/

#include "node.h"
#include <time.h>
#include <random>

using namespace std;

Node* partition(Node* head, int x)
{
  Node* cur = head;
  Node* headmove = nullptr;
  Node* headInitial = nullptr;
  Node* tailmove = nullptr;
  Node* tailInitial = nullptr;

  while (cur) {
    if (cur->value < x) {
        if (headInitial == nullptr) {
          headInitial = cur;
          headmove = headInitial;
        } else {
          headmove->next = cur;
        }
        headmove = cur;
    } else {
        if (tailInitial == nullptr) {
          tailInitial = cur;
          tailmove = tailInitial;
        } else {
          tailmove->next = cur;
        }
        tailmove = cur;
    }
    cur = cur->next;
  }
  headmove->next = tailInitial;
  tailmove->next = nullptr;
  return headInitial;
}

int main()
{
  srand(time(NULL));
  Node* head = nullptr;
  for (int i=0; i < 10; ++i) {
    Insert(head, rand()%10);
  }
  Printf(head);
  Printf(partition(head, 5));
  return 0;
}
