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

void insert2(int* a, int n)
{
  for (int i=1; i < n; ++i) {
    int value = a[i];
    int j = i - 1;
    for (; j >= 0; --j) {
      if (a[j] > value) {
        a[j+1] = a[j];
      }else {
        break;
      }
    }
    a[j+1] = value;
  }
}

int main()
{
  int a[] = {5, 4,3,8,6};
  insert2(a, 5);

  for (int i = 0; i < 5; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
