/*
 * 兑换零钱
*/
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 凑成金额所需要的最少硬币
*/
int coinChange(vector<int>& coins, int amount)
{
  if (amount==0) return 0;
  vector<int> dp(amount+1, amount+1);
  dp[0] = 0;
  for (int i=1; i <= amount; ++i) {
    for (size_t j=0; j < coins.size(); ++j) {
      if (i < coins[j]) {
        continue;
      }
      int coin = coins[j];
      dp[i] = min(dp[i], dp[i-coin] + 1);
    }
  }
  return (dp[amount] == amount +1) ? -1 : dp[amount];
}

int main()
{
  vector<int> coins = {1, 2, 5};
  int amount = 11;
  printf("%d\n", coinChange(coins, amount));
  return 0;
}
