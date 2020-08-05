/*
 * 买卖股票的最佳时机
*/

#include <stdio.h>
#include <vector>

using namespace std;

int BuyStock(const vector<int>& nums)
{
#ifdef GREEDY
  //贪心算法
  int sum = 0;
  for (int i=0; i < nums.size() - 1; ++i) {
    int income = nums[i+1] - nums[i];
    if (income > 0) {
      sum += income;
    }
  }
  return sum;
#else
  //动态规划
  int n = nums.size();
  if (n < 2) {
    return 0;
  }
  vector<vector<int> >dp(n, vector<int>(2));
  //0: 持有现金
  //1: 持有股票
  dp[0][0] = 0;
  dp[0][1] =- nums[0];
  for (int i=1; i < n; ++i) {
    dp[i][0] = max(dp[i-1][0], dp[i-1][1] + nums[i]);
    dp[i][1] = max(dp[i-1][1], dp[i-1][0] - nums[i]);
  }
  return dp[n-1][0];
#endif
}

int main()
{
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  printf("%d\n", BuyStock(nums));
  return 0;
}
