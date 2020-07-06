/*
 * 超级次方
*/

#include <stdio.h>
#include <vector>

using namespace std;
int base = 1371;


//
//公式
//(a*b)%k = (a%k)*(b%k)%k
int Pow(int a, int k)
{
  int res = 1;
  a %= base;
  for (int _=0; _ < k; _++)
  {
    res *= a; 
    res %= base;
  }
  return res;
}

int superPow(int a, vector<int>& b)
{
  if (b.empty()) return 1;
  int l = b.back();
  b.pop_back();
  int part1 = Pow(a, l);
  int part2 = Pow(superPow(a, b), 10);
  return (part1 * part2)% base;
}

int main()
{
  vector<int> b = {1,3,4,5,8,9,3,8,4,2,1,9,3,4};
  printf("%d\n", superPow(2134556345, b));
  return 0;
}
