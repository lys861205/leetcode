/*
 * 一次编辑
*/

#include <string>
#include <stdio.h>

using namespace std;

bool areOneEdit(const string& s1, const string& s2)
{
  int s1_size = s1.size();  
  int s2_size = s2.size();  
  if (abs(s1_size - s2_size) > 1) {
    return false;
  }
  

  string a = s1_size > s2_size ? s1 : s2;
  string b = s1_size > s2_size ? s2 : s1;
  return true;
}

int main()
{
  return 0;
}

