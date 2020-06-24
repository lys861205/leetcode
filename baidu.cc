#include <iostream>
int func(int n, int k)
{
  if (n <= 1) {
    return 1;
  }
  int sum = 0;
  for (int i=1; i < n/2+1; ++i) {
    if ((n-2*i) == k) {
      sum += func(i, k);
      sum += func(n-i, k);
      return sum;
    }
  }
  return 1;
  // int a = 1;
  // int b = n - a;
  // while (a < b) {
  //   if ((b-a) == k) {
  //     sum += func(a, k);
  //     sum += func(b, k);
  //     return sum;
  //   }else {
  //     ++a;
  //     --b;
  //   }
  // }
  // return 1;
}
int main()
{
  std::cout << func(10, 2) << std::endl;
  std::cout << func(10, 3) << std::endl;
  std::cout << func(10, 1) << std::endl;
  std::cout << func(10, 4) << std::endl;
  return 0;
}
