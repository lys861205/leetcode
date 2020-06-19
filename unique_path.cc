#include <stdio.h>
#include <vector>
using namespace std;

// p(i,j) = p(i-1, j) + p(i, j-1) (i >= 1, j>=1)
// p(i,j) = 1 (j==0 || i==0)


int UniquePaths(int m, int n)
{
  if (m == 1 || n == 1) return 1;
  int s = UniquePaths(m-1, n);
  s += UniquePaths(m, n-1);
  return s;
}

int UniquePaths2(int m, int n)
{
  int dp[100][100] = {0};
  for (int i=0; i < m; ++i) {
    for (int j=0; j < n; ++j) {
      if (i==0 || j==0) dp[i][j] = 1; 
      else {
        dp[i][j] = dp[i-1][j] + dp[i][j-1];
      }
    }
  }
  return dp[m-1][n-1];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
{
  int m = obstacleGrid.size();
  int n = obstacleGrid[0].size();
  if (obstacleGrid[0][0] == 1) {
    return 0;
  }
  vector<vector<int> > dp(m, vector<int>(n, 0));
  dp[0][0] = 1;
  for (int i=1; i < m; ++i)
  {
    if (obstacleGrid[i][0] == 1) {
      dp[i][0] = 0;
    } else {
      dp[i][0] = dp[i-1][0]; 
    }
  }
  for (int j=1; j < n; ++j)
  {
    if (obstacleGrid[0][j] == 1) {
      dp[0][j] = 0;
    } else {
      dp[0][j] = dp[0][j-1]; 
    }
  }
  for (int i=1; i < m; ++i) {
    for (int j=1; j < n; ++j) {
      if (obstacleGrid[i][j] == 0){
        dp[i][j] = dp[i-1][j] + dp[i][j-1];
      }else {
        dp[i][j] = 0;
      }
        
    }
  }
  return dp[m-1][n-1];
}

int main()
{
  printf("%d\n", UniquePaths(3, 2));
  printf("%d\n", UniquePaths2(3, 2));
  return 0;
}
