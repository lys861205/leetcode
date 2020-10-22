#include <vector>
#include <stack>
#include <stdio.h>

using namespace std;


vector<int> DailyTemperatures(vector<int>& temperature)
{
  int size = temperature.size();
  vector<int> res(size);

  //存储索引
  stack<int> s;

  for (int i = size - 1; i >= 0; --i) {
    while (!s.empty() && temperature[s.top()] <= temperature[i]) {
      s.pop();
    }
    res[i] = s.empty() ? 0 : (s.top() - i);
    s.push(i);
  }

  return std::move(res);
}

int main()
{
  vector<int> T = {73, 74, 75, 71, 69, 76};
  vector<int> res = DailyTemperatures(T);
  printf("[");
  for (int i=0; i < res.size(); ++i) {
    printf(" %d ", res[i]);
  }
  printf("]\n");
  return 0;
}
