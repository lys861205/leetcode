#include <stdio.h>
#include <vector>

using namespace std;

int composeNum(vector<int>& N, int amount)
{
  vector<int> dp(amount+1, 0);
  dp[0] = 1;
  for (int coin : N) {
    for (int i=1; i < amount+1; ++i) {
      if (i < coin) continue;
      dp[i] += dp[i-coin];
    }
  }
  /*
  for (int i=1; i < amount+1; ++i)
  {
    for (int coin : N) {
      if (i < coin) continue;
      dp[i] += dp[i-coin];
    }
  }
  */
  return dp[amount];
}

int main()
{
  vector<int> N = {1, 2, 5};
  printf("%d\n", composeNum(N, 2));
  printf("%d\n", composeNum(N, 1));
  printf("%d\n", composeNum(N, 5));
  return 0;
}
