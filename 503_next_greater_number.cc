#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;


vector<int> NextGreaterElement(vector<int>& nums)
{
  int size = nums.size();
  vector<int> res(size);
  stack<int> s;
  for (int i=2*size - 1; i >= 0; --i) {
    while (!s.empty() && s.top() <= nums[i%size]) {
      s.pop();
    }
    res[i%size] = s.empty() ? -1 : s.top();
    s.push(nums[i%size]);
  }

  return std::move(res);
}

int main()
{
  vector<int> nums = {2, 1, 2, 4, 3};
  vector<int> res  = NextGreaterElement(nums);
  printf("[ ");
  for (int i=0; i < res.size(); ++i) {
    printf("%d ", res[i]);
  }
  printf("]\n");
  return 0;
}
