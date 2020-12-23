/*
 *
 *  297: 树的序列化和反序列化
*/
#include <stdio.h>
#include "Tree.h"
#include <string>
#include <queue>

using namespace std;

class Codec {
public:
  static size_t ToBuffer(char* & buffer, int size, Tree* t) {
    int n = 0;
    if (t == nullptr) {
      buffer[0] = 4;
      buffer[1] = 'n';
      buffer[2] = 'u';
      buffer[3] = 'l';
      buffer[4] = 'l';
      n = 5;
    } else {
      int value = t->value;
      if (value < 256) {
        buffer[0] = 0x01;
        buffer[1] = value;
        n = 2;
      }
      else {
        buffer[0] = 0x02;
        buffer[1] = value >> 8;
        buffer[2] = value & 0xFF;
        n = 3;
      }
    }
    return n;
  }
  static string Serialize(Tree* root)
  {
    string serial;
    queue<Tree*> q;
    q.push(root);
    while (!q.empty()) {
      int sz = q.size();
      for (int i=0; i < sz; ++i) {
        Tree* tr = q.front();
        q.pop();

        //序列化
        //char buffer[32] = {0};
        char* buffer = (char*)malloc(32);
        size_t n = ToBuffer((char*&)buffer, 32, tr);
        serial.append(buffer, n);

        if (tr) {
          q.push(tr->left);
          q.push(tr->right);
        }
      }
    }
    return serial;
  }

  static Tree* Deserialize(string& buf)
  {
    return nullptr; 
  }
};

void printbinary(const char* str)
{
  char c = *str;
  if (c == '\0') {
    return ;
  }
  int bit = 8;
  while (bit) {
    printf("%d", (c & 0x80) >> 7);
    c = c << 1;
    bit--;
  }
  printf(" ");
  printbinary(++str);
}

int main()
{
  Tree* root = BSTCreate(5);
  Tree* ll = AddLeft(AddLeft(root, 4), 11);
  Tree* _7l = AddLeft(ll, 7);
  Tree* _2r = AddRight(ll, 2);
  Tree* rr= AddRight(root, 8);
  AddLeft(rr, 13);
  AddRight(AddRight(rr, 4), 1);
  Print(root, 3, '*');
  string d = Codec::Serialize(root);
  printf("%s\n", d.data());
  const char* cstr = d.c_str();
  //const char* p = cstr;
  printbinary(cstr);
  printf("\n");
  return 0;
}
