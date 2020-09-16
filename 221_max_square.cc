/*
 * 题号：221
 * 标题：最大正方形，
 * 描述：在一个由0和1组成的二维矩阵中，找到只包含1的最大正方形，并返回面积
*/
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

//dp[i,j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1

int MaxSqure(int (*a)[5], int row, int col)
{
  int dp[100][100] = {0};
  int ans = 0;
  for (int i=0; i < row; ++i) {
    for (int j=0; j < col; ++j) {
      if (a[i][j] == 1) {
        if (i==0 || j==0) {
          dp[i][j] = 1;
        }else {
          dp[i][j] = std::min(std::min(dp[i-1][j], dp[i][j-1]),dp[i-1][j-1]) + 1;
        }
        ans = std::max(ans, dp[i][j]);
      }
    }
  }
  return ans*ans;
}

//动态规划
//dp[i][j] 表示以(i,j)为右下角，且包含1的正方形边长的最大值
//dp[i][j] = 
//std::min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) + 1 (a[i][j] == 1)
//0 (a[i][j] == 0)

int MaxSquare(vector<vector<int> >& square)
{
  int ans = 0;
  vector<vector<int> > dp(square.size(), vector<int>(square[0].size()));
  for (int i=0; i < square.size(); ++i) {
    for (int j=0; j < square[i].size(); ++j) {
      if (square[i][j] == 1) {
        if (i == 0 || j == 0) {
          dp[i][j] = 1;
        } else {
          dp[i][j] = std::min(dp[i-1][j-1], std::min(dp[i-1][j], dp[i][j-1])) + 1;
        }
        ans = std::max(dp[i][j], ans);
      }
    }
  }
  return ans * ans;
}

int main()
{
  int a[][5] = {
    1,0,1,0,0,
    1,0,1,1,1,
    1,1,1,1,1,
    1,0,0,1,0
  };
  vector<vector<int> > square = {
    {1,0,1,0,0},
    {1,0,1,1,1},
    {1,1,1,1,1},
    {1,0,0,1,0}
  };
  printf("%d\n", MaxSqure(a, 4,5));
  printf("%d\n", MaxSquare(square));
  return 0;
}
