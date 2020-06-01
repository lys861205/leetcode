#include <stdio.h>
#include <algorithm>

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

int main()
{
  int a[][5] = {
    1,0,1,0,0,1,0,1,1,1,1,1,1,1,1,1,0,0,1,0
  };
  printf("%d\n", MaxSqure(a, 4,5));
  return 0;
}
