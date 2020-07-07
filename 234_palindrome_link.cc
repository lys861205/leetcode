/*
 * 判断链表是否是回文
*/

#include <stdio.h>
#include "List.h"

Node* reverse(Node* h){
  if (!h) return h;
  Node* pre = nullptr;
  Node* cur = h;
  while (cur) {
    Node* tmp = cur->next;
    cur->next = pre;
    pre = cur;
    cur = tmp;
  }
  return pre;
}

bool isPalindrome(Node* h)
{
  if (!h) return true; 
  Node* slow = h;
  Node* fast = h;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  slow = reverse(slow); 
  Print(h);
  Print(slow);

  Node* p = h;
  while (p && slow) {
    if (p->value != slow->value){
      return false;
    }
    p = p->next;
    slow = slow->next;
  }
  int cnt = 0;
  while (p) {
    cnt++;
    p = p->next;
  } 
  while (slow) {
    cnt++;
    slow = slow->next;
  } 
  if (cnt > 1) {
    return false;
  }
  return true;
}

int main()
{
  Node* h = Add(1);
  {
    Node* l1 = Add(2);
    h->next = l1;
    Node* l2 = Add(2);
    l1->next = l2;
    Node* l3 = Add(1);
    l2->next = l3;
    Node* l4 = Add(1);
    l3->next = l4;
  }
  Print(h);
  printf("%d\n", isPalindrome(h));
  return 0;
}
