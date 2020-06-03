#include <stdio.h>
#include <algorithm>

using namespace std;

int select(int* a, int n)
{
  for (int i = 0; i < n; ++i) {
    int k = i;
    for (int j=i+1; j < n; ++j) {
      if (a[j] < a[k]) k=j;
    }
    if (k!=i) {
      swap(a[k], a[i]);
    }
  }
  return 0;
}

int main()
{
  int a[] = {5, 4,3,8,6};
  select(a, 5);

  for (int i = 0; i < 5; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
