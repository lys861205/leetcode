#include "List.h"

bool hasRing(Node* h)
{
  Node* slow = h;
  Node* fast = h;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      return true;
    }
  }
  return false;
}

int main()
{
  Node dummy;
  Node* h = &dummy;
  for (int i=0; i < 10; ++i) {
    h = Append(h, i); 
  }
  h->next = &dummy;
  printf("%s\n", hasRing(dummy.next) ? "True" : "False");
  return 0;
}
