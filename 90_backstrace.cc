#include <stdio.h>
#include <vector>

using namespace std;

vector<int> result;

int backstrace(int* a, int n, int pos)
{
  printf("[");
  for (size_t i=0; i < result.size(); ++i) {
    printf("%d ", result[i]);
  }
  printf("]\n");
  if (result.size() == n) return 0;
  bool isUsed = false;
  for (int i=pos; i < n; ++i) {
    if (i > 0 && a[i-1] == a[i] && isUsed) continue;
    result.push_back(a[i]);
    backstrace(a, n, i+1);
    result.pop_back();
    isUsed = true;
  }
  return 0;
}

int main()
{
  int a[] = {1, 2, 2};
  backstrace(a, 3, 0);
  return 0;
}
