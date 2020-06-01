#include <stdio.h>
#include <algorithm>

int Helper(int (*a)[3], int row, int col)
{
  int dp[100][100] = {0};
  for (int i = 0; i < row; ++i)
  {
    for (int j=0; j < col; ++j) {
      if (i==0 && j==0) {
        dp[i][j] = a[i][j];
      }
      else if (i==0) {
        dp[i][j] = dp[i][j-1]+a[i][j];
      } 
      else if (j==0){
        dp[i][j] = dp[i-1][j]+a[i][j];
      }
      else {
        dp[i][j] = std::max(dp[i][j-1]+a[i][j], dp[i-1][j]+a[i][j]);
      }
    }
  }
  return dp[row-1][col-1];
}

int MinHP(int (*a)[3], int row, int col)
{
  int dp[100][100] = {0};
  dp[row][col-1] = 1;
  dp[row+1][col] = 1;
  for (int i = row-1; i >=0; --i) {
    for (int j = col-1; j >=0; --j) {
      int min = std::min(dp[i][j+1], dp[i+1][j]);
      dp[i][j] = std::max(1, min - a[i][j]);
    }
  }

  return dp[0][0];
}

int main()
{
  int a[][3] = {
    -2, -3, 3,
    -5, -10, 1,
    10, 30, -5};
  printf("%d\n", Helper(a, 3, 3));
  printf("%d\n", MinHP(a, 3, 3));
  return 0;
}
