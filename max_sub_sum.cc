#include <stdio.h>
#include <algorithm>

int MaxSub(int* a, int n)
{
  if (n==0) return 0;
  if (n==1) return a[0];
  int sum = a[0];
  int value = 0;
  for (int i=0; i < n; ++i) {
    value = std::max(value+a[i], a[i]);
    sum = std::max(sum, value);
  }
  return sum;
}

int MaxSubArray(int* a, int n)
{
  if (n==0) return 0;
  if (n==1) return a[0];
  
  int sum = -9999999;
  for (int i=0; i < n; ++i) {
    int value = MaxSubArray(a, n-1);
    sum = std::max(sum, std::max(value, value+a[n]));
  }
  return sum;
}

int main()
{
  int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  printf("%d\n", MaxSub(a, 9));
  return 0;
}
