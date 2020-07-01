/*
 * 最大子序列号
*/

#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;


// 动态规划解答
int maxSubArray(vector<int>& nums)
{
  int n = nums.size();
  if (n == 0) return 0;
  vector<int> dp(n, 0);
  dp[0] = nums[0];
  int res = dp[0];
  for (int i=1; i < n; ++i) {
    dp[i] = max(dp[i-1] + nums[i], nums[i]);
    res = max(dp[i], res);
  }
  return res;
}

//
int maxSubArray2(vector<int>& nums)
{
  int n = nums.size(); 
  int sum = 0;
  int maxvalue = 0x8fffffff;
  for (int i=0; i < n; ++i) {
    sum += nums[i];
    if (sum < nums[i]) {
      sum = nums[i];
    }
    maxvalue = max(maxvalue, sum);
  }
  return maxvalue;
}

int main()
{
  vector<int> nums = {-3, 4, -1, 2, -6, 1, 4}; 
  printf("%d\n", maxSubArray(nums));
  printf("%d\n", maxSubArray2(nums));
  return 0;
}
