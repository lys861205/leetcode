#include <stdio.h>

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

int main()
{
  printf("%d\n", UniquePaths(3, 2));
  printf("%d\n", UniquePaths2(3, 2));
  return 0;
}
