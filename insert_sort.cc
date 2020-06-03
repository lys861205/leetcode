#include <stdio.h>
#include <algorithm>

using namespace std;

int insert(int* a, int n)
{
  for (int i=1; i<n; ++i) {
    for (int j=0; j < i; ++j) {
      if (a[j] > a[i]) {
        swap(a[i], a[j]);
      }
    }
  }
  return 0;
}

int main()
{
  int a[] = {5, 4,3,8,6};
  insert(a, 5);

  for (int i = 0; i < 5; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
