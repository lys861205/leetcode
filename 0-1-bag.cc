/*
 * 背包问题
*/
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 遍历所有可能的组合，从中选中价值最大的组合
*/
int bag(int W, vector<int>& wt, vector<int>& val, int pos)
{
  if (W<=0) return 0;
  int n = wt.size();
  int res = 0;
  for (int i=pos; i < n; ++i) {
    if (W < wt[i]) {
      continue;
    }
    res = max(res, bag(W-wt[i], wt, val, i+1) + val[i]);
  }
  return res;
}

int knapsack(int W, int N, vector<int>& wt, vector<int>& val)
{
  vector<vector<int> > dp(N+1, vector<int>(W+1, 0));
  for (int i=1; i <= N; ++i) {
    for (int w=1; w <= W; ++w) {
      if (w-wt[i-1] < 0) {
        dp[i][w] = dp[i-1][w];
      } 
      else {
        dp[i][w] = max(dp[i-1][w-wt[i-1]]+val[i-1],// 装入背包
                       dp[i-1][w]                  // 不装入背包
                       );
      }
    }
  }
  return dp[N][W];
}

int main()
{
  vector<int> wt = {2, 1, 3};
  vector<int> val = {4, 2, 3};
  printf("%d\n", bag(4, wt, val, 0));
  //printf("%d\n", knapsack(4, 3, wt, val));

  vector<int> wt2 = {12, 2, 1, 4, 1};
  vector<int> val2 = {4, 2, 1, 10, 2};
  printf("%d\n", bag(15, wt2, val2, 0));
  //printf("%d\n", knapsack(15, 5, wt, val));

{
  vector<int> wt2 = {12, 5};
  vector<int> val2 = {4, 10};
  printf("%d\n", bag(15, wt2, val2, 0));
  //printf("%d\n", knapsack(15, 2, wt, val));
}
  return 0;
}
