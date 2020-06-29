#include <stdio.h>
#include "List.h"
#include <stack>

using namespace std;

Node* reverse(Node* head)
{
  Node* cur = head;
  Node* pre = NULL;
  while (cur) {
    Node* tmp = cur->next;
    cur->next = pre;
    pre = cur;
    cur = tmp;
  }
  return pre;
}

Node* reverseKGroup2(Node* head, int k)
{
  Node* temp = head;  
  for (int i = 1; i < k && temp != NULL; ++i)
  {
    temp = temp->next;
  }
  if (temp == NULL) return head;
  Node* t2 = temp->next;
  temp->next = NULL;
  Node* newHeader = reverse(head);
  head->next = reverseKGroup2(t2, k);
  return newHeader;
}

Node* reverseKGroup(Node* head, int k)
{
  Node* p = head;
  stack<Node*> st;
  Node* new_head = NULL;
  Node* q = NULL;
  while (p) {
    st.push(p);
    p = p->next;
    if (st.size() == k) {
      while (!st.empty())
      {
        Node* sp = st.top();
        st.pop();
        if (q) {
          q->next = sp; 
        }
        q = sp;
        if (!new_head) {
          new_head = q;
        }
      }
    }
  }
  Node* last = NULL;
  Node* qq = NULL;
  while (!st.empty()){
    qq = st.top(); 
    st.pop();
    qq->next = last;
    last = qq;
  }
  q->next = qq;
  return new_head;
}

int main()
{
  Node* head = NULL;
  for (int i=0; i <= 10; ++i) {
    Node* l = Add(i);
    l->next = head;
    head = l;
  }
  Print(head);
  Node* newHeader = reverseKGroup2(head, 3);
  Print(newHeader);
  //newHeader = reverseKGroup(head, 3);
  //Print(newHeader);
  return 0;
}
