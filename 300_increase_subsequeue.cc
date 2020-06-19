#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

//dp[i] = dp[j] + 1 (0 < j < i)
//

int lengthOfLIS(vector<int>& nums)
{
  int maxlen = 0;
  vector<int> dp(nums.size(), 0);
  for (size_t i = 0; i < nums.size(); ++i) {
    dp[i] = 1;
    for (size_t j=0; j < i; ++j) {
      if (nums[i] < nums[j]) {
        dp[i] = max(dp[i], dp[j]+1);
      } else {
        //dp[i] = max(dp[i], dp[j]);
      }
    }
    if (maxlen < dp[i]) {
      maxlen = dp[i];
    }
  }
  return maxlen;
}

int main()
{
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  printf("%d\n", lengthOfLIS(nums));
  return 0;
}

