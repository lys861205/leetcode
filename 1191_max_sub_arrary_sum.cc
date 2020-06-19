#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

//dp[i] = max(dp[i-1], dp[i-1]+a[i])

int kConcatenationMaxSum(vector<int>& arr)
{
  int maxvalue = 0;
  int s = arr.size(); 
  vector<int> dp(s, 0);
  if (arr[0] > 0) {
    dp[0] = arr[0];
  } else {
    dp[0] = 0;
  }
  for (int i=1; i < s; ++i) {
    if (arr[i]> 0) {
      dp[i] = max(dp[i-1], dp[i-1]+arr[i]);
    } else {
      dp[i] = 0;
    }
    if (dp[i] > maxvalue) {
      maxvalue = dp[i];
    }
  }

  return maxvalue;
}

int main()
{
  vector<int> arr = {1, -2, 1, 1, -2 ,1,1,-2,1,1,-2,1,1,-2,1};
  printf("%d\n", kConcatenationMaxSum(arr));

  vector<int> arr1 = {1,2,1,2,1,2};
  printf("%d\n", kConcatenationMaxSum(arr1));

  vector<int> arr2 = {-1,-2,-1,-2,-1,-2,-1,-2,-1,-2,-1,-2};
  printf("%d\n", kConcatenationMaxSum(arr2));
  return 0;
}
