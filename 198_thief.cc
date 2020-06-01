#include <stdio.h>
#include <algorithm>



//dp[i] = max(dp[i-2] + a[i], dp[i-1]);

int MaxMoney(int* a, int n)
{
  int* dp = new int[n+1];
  if (n==1) return a[0];
  if (n==2) return std::max(a[0], a[1]);
  dp[0] = a[0];
  dp[1] = std::max(a[0], a[1]);
  for (int i = 2; i < n; ++i) {
    dp[i] = std::max(dp[i-2] + a[i], dp[i-1]);
  }
  return dp[n-1];
}

int main()
{
  int a[] = {2, 7, 9, 3, 1};
  printf("%d\n", MaxMoney(a, 5));
  int b[] = {1, 2, 3, 1};
  printf("%d\n", MaxMoney(b, 4));
  return 0;
}
