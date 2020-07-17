/*
 * 检测环
*/

#include "node.h"

bool areCycle(Node* head)
{
  Node* slow = head;
  Node* fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      return true;
    }
  }
  return false;
}

Node* getCycle(Node* head)
{
  Node* slow = head;
  Node* fast = head;
  bool is_cycle = false;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      is_cycle = true;
      break;
    }
  }
  if (!is_cycle) return nullptr;
  
  Node* meet = fast;
  Node* begin = head;
  while (meet != begin) {
    meet = meet->next;
    begin = begin->next;
  }
  return meet;
}

int main()
{
  Node* cross = new Node(1000);
  Node* p = nullptr; 
  for (int i=0; i < 10; ++i) {
    Insert(p, i);
    if (i == 5) {
      cross->next = p;
      p = cross;
    }
  }
  Printf(p);
  Tail(p)->next = cross;
  Node* cycle_node  = getCycle(p);
  cycle_node->next = nullptr;
  Printf(cycle_node);
  return 0;
}
