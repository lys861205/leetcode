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

//递归方法判断 时间复杂度O(n) 空间复杂度O(n)
Node* left;

bool traverse(Node* right) 
{
  if (nullptr == right) return true;
  bool res = traverse(right->next);
  res = res && (left->value == right->value);
  left = left->next;
  return res;
}
bool IsPalindrome(Node* h)
{
  left = h;
  return traverse(h);
}


//快慢指针找到中点
bool isPalindrome(Node* h)
{
  if (!h) return true; 
  Node* slow = h;
  Node* fast = h;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  if (fast) { //奇数个节点
    slow = slow->next; 
  }
  Node* left = h;
  Node* right = reverse(slow); 
  Print(h);
  Print(slow);

  while (right) {
    if (left->value != right->value) {
      return false;
    }
    left = left->next;
    right = right->next;
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
    //Node* l4 = Add(1);
    //l3->next = l4;
  }
  Print(h);
  //printf("%d\n", isPalindrome(h));
  printf("%d\n", IsPalindrome(h));
  return 0;
}
