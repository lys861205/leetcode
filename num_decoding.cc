#include <stdio.h>

int numDecoding(char* a, int n)
{
  if (n==0) return 0;
  int prev = 1, curr = 1;
  for (int i=1; i <n ; ++i)
  {
    int tmp = curr;
    if (a[i]=='0') {
      if (a[i-1] == '1' || a[i-1] == '2') {
        curr = prev; 
      }
    }
    else if (a[i-1] = '1' || a[i-1] == '2' && (a[i] >= '1' && a[i] <= '6')) {
      curr =  curr + prev;
    }
    prev = tmp;
  }
  return curr;
}

int numDecoding2(char* a, int n)
{
  int sum = 1;
  if (n==0) return 0;
  int m = n-1;
  if (a[m] == '0' && (a[m-1] == '2' || a[m-1] == '1')) {
    sum += numDecoding2(a, n-2); 
  }
  else if ((a[m-1] == '2' || a[m-1] == '1') && (a[m] >= '1' && a[m] <= '6')) {
    sum += numDecoding2(a, n-1) + numDecoding2(a, n-2);
  }
  else if (a[m] >= '1' && a[m] <= '6') {
    //return 1;
  }
  return sum;
}

int main()
{
  char a[] = {'2', '2', '6'};
  printf("%d\n", numDecoding(a, 3));
  char b[] = {'2', '2', '6', '0', '2', '1', '4', '6'};
  printf("%d\n", numDecoding(b, 8));
  printf("%d\n", numDecoding2(a, 3));
  printf("%d\n", numDecoding2(b, 8));
  return 0;
}
