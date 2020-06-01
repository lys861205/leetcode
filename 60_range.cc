#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

vector<int> result;
set<int> index;

int kbackstrace(int* a, int n, int& k)
{
  if (result.size() == n) {
    --k;
    if (k == 0){
      printf("[");
      for (size_t i=0; i < result.size(); ++i) {
        printf("%d ", result[i]);
      }
      printf("]\n");
      return -1;
   }
  } else {
    bool used = false;
    for (int i = 0; i < n; ++i) {
      if (i > 0 && a[i] == a[i-1] && used) continue;
      if (index.count(i) > 0) continue;
      index.insert(i);
      result.push_back(a[i]); 
      if (-1 == kbackstrace(a, n, k)) return 0;
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
  int k = 2;
  kbackstrace(a, 4, k);
  return 0;
}
