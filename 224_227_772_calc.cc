/*
 * 计算器
*/

#include <stdio.h>
#include <string>
#include <stack>

using namespace std;

bool isdigit(char c)
{
  if (c >= '0' && c <= '9') {
    return true;
  } else {
    return false;
  }
}

int calculate(string& s, int& i)
{
  char sign = '+';
  int num = 0;
  int sum = 0;
  stack<int> st;
  for (;i < s.size(); ++i)
  {
    if (isdigit(s[i])) {
      num = 10 * num + (s[i] - '0');
    }
    if (s[i] == '(') {
      num = calculate(s, ++i);
    }
    if (!isdigit(s[i]) && s[i] != ' '|| i == s.size() -1) {
      switch(sign) {
        int tmp;
        case '+': st.push(num);break;
        case '-': st.push(-num);break;
        case '/': tmp = st.top();st.pop();st.push(tmp/num);break;
        case '*': tmp = st.top();st.pop();st.push(tmp*num);break;
      }
      sign = s[i];
      num = 0;
    }
    if (s[i] == ')') {
      ++i;
      break;
    }
  }
  while (!st.empty()){
    sum += st.top();
    st.pop();
  }
  return sum;
}

int main()
{
  string s = "(3 + (1 + 1) * 2) * 2 + (3/1)";
  int idx = 0;
  printf("%d\n", calculate(s,idx));
  return 0;
}
