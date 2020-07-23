/*
 * 链表排序
*/
#include "List.h"
Node* merge(Node* l1, Node* l2) 
{
  Node dummy;
  Node* p = &dummy;

  while(l1 && l2) {
    if (l1->value < l2->value) {
      p->next = l1;
      p = l1;
      l1 = l1->next;
    } else {
      p->next = l2; 
      p = l2;
      l2 = l2->next;
    }
  }
  if (l1) {
    p->next = l1;
    l1 = l1->next;
  }
  if (l2) {
    p->next = l2;
    l2 = l2->next;
  }
  return dummy.next;
}

Node* cut(Node* l, int s)
{
  Node* p = l;
  while (--s && p) {
    p = p->next; 
  }
  if (!p) return p;
  Node* q = p->next;
  p->next = nullptr;
  return q;
}

//迭代空间复杂度O(1)
Node* SortList(Node* head)
{
  if (!head || !head->next) return head;
  int len = 0;
  Node* p = head;
  while (p) {
    ++len;
    p = p->next;
  }
  Node dummy;
  dummy.next = head;
  for (int i=1; i < len; i *=2) {
      Node* cur = dummy.next;
      Node* tail = &dummy;
      while (cur) {
        Node* left = cur;
        Node* right = cut(left, i);
        cur = cut(right, i);
        tail->next = merge(left, right);
        while (tail->next) {
          tail = tail->next;
        }
      }
  }
  return dummy.next;
}


//递归
Node* RecursiveSortList(Node* head) 
{
  if (!head || !head->next) return head;
  Node* slow = head;
  //Node* fast = head->next->next;
  Node* fast = head;
  Node* prev = nullptr;
  while (fast && fast->next) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  Node* mid = nullptr;
  if (!fast) { //偶数
    mid = slow;
    prev->next = nullptr;
  } else {
    mid = slow->next;
    slow->next = nullptr;
  }
  Node* left = RecursiveSortList(head);
  Node* right = RecursiveSortList(mid);
  return merge(left, right);
}


int main()
{
  Node dummy;
  Node* head = &dummy;
  InsertTail(head, 4);
  InsertTail(head, 2);
  InsertTail(head, 5);
  InsertTail(head, 3);
  // for (int i=1; i < 10; ++i) {
  //   InsertTail(head, i);
  // }
  Print(dummy.next);
  //Print(SortList(dummy.next));
  Print(RecursiveSortList(dummy.next));
  return 0;
}

