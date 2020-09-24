#include "List.h"

Node* DeleteKthNode(Node* h, int k)
{
  if (!h) return h;
  Node* p = h;
  Node* q = h;
  while (k && q) {
    q = q->next;
    k--;
  }
  if (k==0 && q == nullptr) {
    h = h->next;
    return h;
  }
  else if (k > 0) {
    return h; 
  }
  
  Node* prev = nullptr;
  while (q) {
    prev = p; 
    p = p->next;
    q = q->next;
  }
  prev->next = prev->next->next;
  return h;
}

int main(int argc, char* argv[]) 
{
  Node dummy;
  Node* h = &dummy;
  for (int i=0; i < 10; ++i) {
    h = Append(h, i); 
  }
  Printf(dummy.next);
  Printf(DeleteKthNode(dummy.next, 10));
  return 0;
}
