#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

vector<int> result;
set<int> index;

int kbackstrace(int* a, int n, int pos)
{
  if (result.size() >= 0 &&  result.size() <= n) {
      printf("[");
      for (size_t i=0; i < result.size(); ++i) {
        printf("%d ", result[i]);
      }
      printf("]\n");
  } 
    
  for (int i = pos; i < n; ++i) {
    result.push_back(a[i]); 
    kbackstrace(a, n, i+1);
    result.pop_back();
  }
  return 0;
}

int main()
{
  int a[] = {1,2,3,4};
  int k = 2;
  kbackstrace(a, 4, 0);
  return 0;
}
