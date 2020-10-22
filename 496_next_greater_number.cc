#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

vector<int> NextGreaterElement(vector<int>& nums)
{
  vector<int> res(nums.size());
  stack<int> s;
  int size = nums.size();
  for (int i = size-1; i >=0; --i){
    while (!s.empty() && s.top() <= nums[i]) {
      s.pop();
    }
    res[i] = s.empty() ? -1 : s.top();
    s.push(nums[i]);
  }

  return std::move(res);
}

int main()
{
  vector<int> nums = {2, 1, 2, 4, 3};
  vector<int> res = NextGreaterElement(nums);
  printf("[");
  for (int i=0; i < res.size(); ++i) {
    printf("%d ", res[i]);
  }
  printf("]\n");
  return 0;
}
