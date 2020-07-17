/*
 * 判断是否是回文链表
*/

#include "node.h"

Node* left;
bool travel(Node* right)
{
  if (!right) return true; 
  bool res = travel(right->next);
  res = res && (left->value == right->value);
  left = left->next;
  return res;
}

bool IsPalindrome2(Node* head)
{
  if (!head || !head->next) return true;
  left = head; 
  return travel(head->next);
}

//============================================

Node* reverse(Node* head)
{
  Node* curr = head;
  Node* prev = NULL;
  while (curr) {
    Node* temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }
  return prev;
}

bool IsPalindrome(Node* head)
{
  if (!head || !head->next) return true;
  Node* slow = head;
  Node* fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  if (fast) { //奇数链表
    slow = slow->next; 
  }
  Node* eP = reverse(slow);
  Node* sP = head;
  while (eP) {
    if (eP->value != sP->value) {
      return false;
    }
    eP = eP->next;
    sP = sP->next;
  }
  return true;
}

int main()
{
  Node* head;
  Insert(head, 1);
  Insert(head, 2);
  Insert(head, 3);
  Insert(head, 2);
  Insert(head, 1);
  Printf(head);
  printf("%s\n", IsPalindrome2(head) ? "true" : "false");
  return 0;
}
