#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

vector<int> result;
set<int> index;

int backstrace(int* a, int n)
{
  if (result.size() == n) {
    printf("[");
    for (size_t i=0; i < result.size(); ++i) {
      printf("%d ", result[i]);
    }
    printf("]\n");
  } else {
    bool used = false;
    for (int i = 0; i < n; ++i) {
      if (i > 0 && a[i] == a[i-1] && used) continue;
      if (index.count(i) > 0) continue;
      index.insert(i);
      result.push_back(a[i]); 
      backstrace(a, n);
      result.pop_back();
      index.erase(i);
      used = true;
    }
  }
  return 0;
}

int main()
{
  int a[] = {1,2,3,4};
  backstrace(a, 4);
  int b[] = {1,1,2};
  backstrace(b, 3);
  return 0;
}
