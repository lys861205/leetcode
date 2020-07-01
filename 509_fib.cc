/*
 * 斐波那契数
*/

#include <stdio.h>
int fib(int N)
{
  if (N == 0) return 0;
  if (N == 1) return 1;
  int i_0 = 0;
  int i_1 = 1;
  int sum = 0;
  for (int i = 2; i <= N; ++i) 
  {
    sum = i_0 + i_1; 
    i_0 = i_1;
    i_1 = sum;
  }
  return sum;
}

int main()
{
  printf("%d\n", fib(40));
  return 0;
}
