/*
 *  打家劫舍
*/

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int rob2(vector<int>& nums)
{
  int n = nums.size();
  if (n==0) return 0;
  // else if (n==1) return nums[0];
  // else if (n==2) return max(nums[0], nums[1]);
  vector<int> dp(n, 0);
  dp[0] = nums[0];
  dp[1] = max(nums[0], nums[1]);
  for (int i=2; i < n; ++i) {
    dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
  }
  return dp[n-1];
}

int rob(vector<int>& nums)
{
  int n = nums.size();
  if (n==0) return 0;
  else if (n==1) return nums[0];
  else if (n==2) return max(nums[0], nums[1]);

  vector<int> forward(nums.begin(), nums.end()-1);
  vector<int> backward(nums.begin()+1, nums.end());
  return max(rob2(forward), rob2(backward));
}

int main()
{
  vector<int> nums = {2, 3, 2};
  vector<int> nums1 = {2};
  vector<int> nums2 = {};
  vector<int> nums3 = {2,3,4,5,6,7,8,9,10,2,35,7,8,9};
  printf("%d\n", rob(nums));
  printf("%d\n", rob(nums1));
  printf("%d\n", rob(nums2));
  printf("%d\n", rob(nums3));
  return 0;
}


