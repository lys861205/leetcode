#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

vector<int> result;
set<int> calc;

int Permutation(int* a, int n)
{
  if (result.size() > 0 ) {
    printf("[");
    for (size_t i = 0 ; i < result.size(); ++i) {
      printf("%d ", result[i]);
    }
    printf("]\n");
  }
  if (n==result.size()) {
    //printf("[");
    // for (set<int>::iterator it = result.begin(); it != result.end(); ++it) {
    //   printf("%d ", *it);
    // }
    // for (size_t i = 0 ; i < result.size(); ++i) {
    //   printf("%d ", result[i]);
    // }
    // printf("]\n");
    return 0;
  }
  for (int i=0; i < n; ++i) {
    if (calc.count(a[i]) >0 ) {
      continue;
    }
    calc.insert(a[i]);
    result.push_back(a[i]);
    Permutation(a, n);
    calc.erase(a[i]);
    result.pop_back();
  }
  return 0;
}

int main()
{
  int a[] = {1,2,3};
  Permutation(a, 3);
  int b[] = {1,2,3, 4, 5, 6};
  //Permutation(b, 6);
  return 0;
}
