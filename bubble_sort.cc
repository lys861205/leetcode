#include <stdio.h>
#include <algorithm>

using namespace std;

int bubble(int* a, int n) 
{
  for (int i=0; i < n-1; ++i) {
    for (int j=0; j < n-i-1; ++j) {
      if (a[j+1] < a[j]) swap(a[j+1], a[j]); 
    }
  }
  return 0;
}

int main()
{
  int a[] = {5, 4,3,8,6};
  bubble(a, 5);

  for (int i = 0; i < 5; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
