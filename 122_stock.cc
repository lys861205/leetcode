/*
 * 多次买卖一只股票，利润最大
*/

#include <vector>
#include <iostream>
using namespace std;

int maxProfix(vector<int>& prices)
{
  if (prices.size() <= 0) return 0;
  vector<vector<int> > dp(prices.size(), vector<int>(2));
  int n = prices.size();
  dp[0][0] = 0;
  dp[0][1] = -prices[0];
  for (int i=1; i < n; ++i) {
    dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]); 
    dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]); 
  }
  return dp[n-1][0];
}

int maxProfix2(vector<int>& prices)
{
  if (prices.size() <= 0) return 0;
  int cur_sell = 0;
  int cur_buy  = -prices[0];
  for (int i=1; i < prices.size(); ++i) {
    cur_sell = max(cur_sell, cur_buy + prices[i]);
    cur_buy = max(cur_buy, cur_sell - prices[i]);
  }
  return cur_sell;
}

int main()
{
  vector<int> prices = {
    7,1,5,3,6,4
  };
  std::cout << maxProfix(prices) << std::endl;
  std::cout << maxProfix2(prices) << std::endl;
  return 0;
}
