/*
 * 煎饼排序
*/

#include <stdio.h>
#include <vector>

using namespace std;

/*
 * 步骤
 * 1 找出面积最大的蛋糕
 * 2 把面积最大的蛋糕翻转到最上面
 * 3 然后把最上面的翻转到下面
 * 4 重复步骤1 2 3
*/

void reverse(vector<int>& cakes, int start, int end)
{
  while (start < end) {
    swap(cakes[start], cakes[end]);
    ++start;
    --end;
  }
}

void sort(vector<int>& cakes, int n, vector<int>& res)
{
  if (n==1) return;
  //寻找面积最大的蛋糕
  int maxCake = 0;
  int maxIndex = 0;
  for (int i=0; i < n; ++i) {
    if (cakes[i] > maxCake) {
      maxCake = cakes[i];
      maxIndex = i;
    }
  }
  //2
  reverse(cakes, 0, maxIndex);
  res.push_back(maxIndex+1);
  //3
  reverse(cakes, 0, n-1);
  res.push_back(n);
  //4
  sort(cakes, n-1, res);
}

vector<int> pancakeSore(vector<int>& cakes)
{
  vector<int> res;
  sort(cakes, cakes.size(), res);
  return res;
}

int main()
{
  vector<int> cakes = {3, 2, 4, 1};
  vector<int> res = std::move(pancakeSore(cakes));
  for (int i=0; i < res.size(); ++i) 
  {
    printf("%d ", res[i]);
  }
  printf("\n");
  return 0;
}
