#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int findLength(vector<int>& A, vector<int>& B) {
  int maxlen = 0;
  vector<vector<int> > dp(A.size(), vector<int>(B.size(),0));
  for(int i=0;i<A.size();i++) {
    if(A[i]==B[0]) {maxlen=1;dp[i][0]=1;}
  }
  for(int j=1;j<B.size();j++) {
    if(A[0]==B[j]) {maxlen=1;dp[0][j]=1;}
  }
  for (int i=1; i < A.size(); ++i){
    for (int j=1; j < B.size(); ++j){
      if (A[i] == B[j]) {
        dp[i][j] = dp[i-1][j-1]+1;
        maxlen = max(maxlen, dp[i][j]);
      }
      else {
        dp[i][j] = 0;
      }
    }
  }
  return maxlen;
}

int main()
{
  vector<int> a = {0, 1, 1, 1, 1};
  vector<int> b = {1, 0, 1, 0, 1};
  printf("%d\n", findLength(a, b));
  return 0;
}

