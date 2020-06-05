/*
 * 给定一个整数，求组成二叉树有多少种
*/

#include <stdio.h>

//G(n)= ∑_(i=1)^n▒〖f(i,n)〗
//f(i,n) = G(i-1)*G(n-i)

//G(n) = ∑_(i=1)^n▒G(i-1)*G(n-i)

int numberTrees(int n)
{
  int* G = new int[n+1];
  G[0] = 1;
  G[1] = 1;
  for (int i=2; i <= n; ++i) {
    for (int j=1; j <= i; ++j) {
      G[i] += G[j-1]*G[i-j];
    }
  }
  return G[n];
}

int main()
{
  int n = 1000;
  printf("%d\n", numberTrees(n));
  return 0;
}
