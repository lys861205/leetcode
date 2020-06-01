#include <stdio.h>

int climbStairs(int n)
{
  if (n==1) return 1;
  if (n==2) return 2;

  int sum = climbStairs(n-1);
  sum += climbStairs(n-2);
  return sum;
}

int climbStairs2(int n)
{
  if (n==1) return 1;
  if (n==2) return 2;
  int i_1 = 1;
  int i_2 = 2;
  int sum = 0;
  for (int i=2; i <n; i++) {
    sum = i_1 + i_2; 
    i_1 = i_2;
    i_2 = sum;
  }
  return sum;
}

int main()
{
  printf("%d\n", climbStairs(2));
  printf("%d\n", climbStairs(4));
  printf("%d\n", climbStairs(10));
  printf("==========================\n");
  printf("%d\n", climbStairs2(2));
  printf("%d\n", climbStairs2(4));
  printf("%d\n", climbStairs2(10));
  return 0;
}
