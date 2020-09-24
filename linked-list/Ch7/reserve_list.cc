#include "List.h"


LinkNode* reserve(LinkNode* l)
{
  LinkNode* cur = l;
  LinkNode* pre = nullptr;
  while (cur) {
    LinkNode* tl = cur->next;
    cur->next = pre;
    pre = cur;
    cur = tl;
  }
  return pre;
}

int main()
{
  Node dummy;
  Node* h = &dummy;
  for (int i=0; i < 10; ++i) {
    h = Append(h, i); 
  }
  Printf(dummy.next);
  Printf(reserve(dummy.next));
  return 0;
}


