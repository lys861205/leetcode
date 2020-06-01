#include <stdio.h>
#include <algorithm>

int MaxSubMul(int* a, int n)
{
  int l_min = 0x7fffffff;
  int l_max = 0x80000000;
  int max = 0x80000000;

  for (int i = 0; i < n; ++i) {
    if (a[i] < 0) {
      int tmp = l_max;
      l_max = l_min;
      l_min = tmp;
    }
    l_max = std::max(l_max*a[i], a[i]);
    l_min = std::min(l_min*a[i], a[i]);
    max = std::max(max, l_max);
  }
  return max;
}

int main()
{
  int a[] = {5, 6, -3, 4, 0};
  printf("%d\n", MaxSubMul(a, 5));
  
  int max = 0x80000000;
  int l_min = 0x7fffffff;
  printf("%d %d\n", l_min, max);
  return 0;
}
