/*
 * 计算质数
 */

#include <stdio.h>
#include <vector>
using namespace std;

int countPrimes(int n)
{
  vector<bool> isPrim(n, true);  
  for (int i=2; i*i < n; ++i){
    if (isPrim[i]) {
      for (int j=i*i; j < n; j +=i) {
        isPrim[j] = false;
      }
    }
  }
  int count = 0;
  for (int i=1; i < n; ++i) {
    if (isPrim[i]) 
    {
      printf("%d ", i);
      count++; 
    }
  }
  printf("\n");
  return count;
}

int main()
{
  printf("%d\n", countPrimes(100000000));
  return 0;
}

