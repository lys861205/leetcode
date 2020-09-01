/*
让字符串成为回文串的最少插入次数
*/

#include <vector>
#include <string>

using namespace std;

//定义： 对s[i..j],最少需要插入的dp[i][j]次能变成回文
// dp[i][j] = dp[i+1][j-1] (s[i] == s[j])
// dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1  (s[i] != s[j])

int minInsertions(const string& s)
{
  int n = s.size();
  vector<vector<int> > dp(n, vector<int>(n, 0));
  for (int i=n-2; i >= 0; --i) {
    for (int j=i+1; j < n; ++j) {
      if (s[i] == s[j]) {
        dp[i][j] = dp[i+1][j-1];
      }else {
        dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
      }
    }
  }
  return dp[0][n-1];
}

int main()
{
  return 0;
}
