#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

string longestPailndrome(string s)
{
  int size = s.size();
  int maxlen = 0;
  int start = 0;
  vector<vector<int> > dp(size, vector<int>(size, 0));
  for (int r=1; r < size; ++r) {
    for (int l=0; l < r; ++l) {
      if (s[r] == s[l]) {
        if (r-l < 3) {
          dp[l][r] = true;
        } else {
          dp[l][r] =  dp[l+1][r-1];
        }
      } else {
        dp[l][r] = false;
      }

      if (dp[l][r]) {
        if ((r-l) > maxlen) {
          maxlen = r-l;
          start = l;
        }
      }
    }
  }
  return s.substr(start, maxlen);
}

int longestPailndrome(const char* s, int n)
{
  if (s == 0 || n < 1) {
    return 0;
  }
  int max = 0;
  int len = 0;
  for (int i=0; i < n; ++i) {
    for (int j=0; i>=j && (i+j) < n; ++j) {
      if (s[i-j] != s[i+j]) {
        break;
      }
      len = j*2+1;
    }
    if (max < len) {
      max = len;
    }
    int  m = i;
    for (int k=1; m>=0 && (i+k) < n; --m,++k) {
      if (s[m] != s[i+k]) {
        break;
      }
      len = k*2;
    }
    if (max < len) {
      max = len;
    }
  }
  return max;
}

int main()
{
  const char* s = "abba";
  printf("%d\n", longestPailndrome(s, 4));
  const char* b = "babad";
  printf("%d\n", longestPailndrome(b, 5));
  const char* c = "cbbd";
  printf("%d\n", longestPailndrome(c, 4));
  const char* d = "abc";
  printf("%d\n", longestPailndrome(d, 3));
  return 0;
}
