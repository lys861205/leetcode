/*
 * 鸡蛋掉落
*/


/**
* @brief 
*
* @param k 鸡蛋数量
* @param n 楼层数
*
* @return 
*/
//dp[k][n] = max(dp[k-1][i-1], dp[k][n-i]);
//第i层扔鸡蛋,鸡蛋碎 dp[k-1][i-1], 鸡蛋数量减1，楼层i-1
//第i层扔鸡蛋,鸡蛋没有碎 dp[k][n-i], 鸡蛋数量不变，需要尝试i层以上，剩余楼层数量n-i
#include <stdio.h>
#include <algorithm>
#include <unordered_map>
#include <tuple>

using namespace std;

int dp(int k, int n);

int eggsDrop(int k, int n)
{
  //unordered_map<tuple<int, int>, int> memo; 
  //return dp(memo, k, n)
  return dp(k, n);
}

int dp(int k, int n)
{
  if (k == 1) return n;
  if (n == 0) return 0;
  int res = 0x7fffffff;
  for (int i=1; i <=n; ++i) {
    res = min(res, 
              max(
              dp(k-1, i-1),  // 鸡蛋碎了，往下走
              dp(k, n-i)     // 鸡蛋没有碎，往上走
              ) 
              + 1);
  }
  return res;
}

int main()
{
  printf("%d\n", eggsDrop(2, 10));
  printf("%d\n", eggsDrop(2, 6));
  return 0;
}
