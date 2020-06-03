#include <stdio.h>
#include <algorithm>

using namespace std;

int maxProfit(int* a, int n)
{
  int minP = 0x7fffffff;
  int maxProfi = 0;
  for (int i=0; i < n; ++i) {
    maxProfi = max(maxProfi, a[i] - minP); 
    minP = min(a[i], minP);
  }
  return maxProfi;
}

int main()
{
  int a[] = {2, 5, 2, 1, 9};
  printf("%d\n", maxProfit(a, 5));
  return 0;
}
