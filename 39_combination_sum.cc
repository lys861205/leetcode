#include <stdio.h>
#include <stack>
#include <vector>

using namespace std;

//stack<int> res;
vector<int> res;

int backstrace(int* a, int n, int start, int target)
{
  int sum = 0;
  for (size_t i=0; i < res.size(); ++i) {
    sum += res[i]; 
  }
  if (sum == target) {
    return 0;
  }
  else if (res.size() == n || sum > target) {
    return -1;
  }
  for (int i=start; i < n; ++i) {
    res.push_back(a[i]);
    if (0==backstrace(a, n, i, target)) {
      printf("[");
      for (int i=0; i < res.size(); ++i) {
        printf("%d ", res[i]);
      }
      printf("]\n");
    }
    res.pop_back();
  }
  return -1;
}

int onebackstrace(int* a, int n, int start, int target)
{
  int sum = 0;
  for (size_t i=0; i < res.size(); ++i) {
    sum += res[i]; 
  }
  if (sum == target) {
    return 0;
  }
  else if (res.size() == n || sum > target) {
    return -1;
  }
  for (int i=start; i < n; ++i) {
    res.push_back(a[i]);
    if (0==onebackstrace(a, n, i+1, target)) {
      printf("[");
      for (int i=0; i < res.size(); ++i) {
        printf("%d ", res[i]);
      }
      printf("]\n");
    }
    res.pop_back();
  }
  return -1;
}

int main()
{
  int a[] = {2,1,5,9,10,3,4,8,6,7};
  backstrace(a,10,0,88);
  onebackstrace(a,10,0,88);
  return 0;
}
