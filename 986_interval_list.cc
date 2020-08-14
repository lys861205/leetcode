#include <stdio.h>
#include <vector>

using namespace std;


vector<vector<int> > Intersection(const vector<vector<int> >& a, const vector<vector<int> >& b)
{
  vector<vector<int> > res;
  int a_len = a.size();
  int b_len = b.size();
  int i = 0, j = 0;
  while (i < a_len && j < b_len) {
    int a0 = a[i][0], a1 = a[i][1];
    int b0 = b[j][0], b1 = b[j][1];
    if (!(b0 > a1 || a0 > b1)) {
      vector<int> tmp = {std::max(a0, b0), std::min(a1, b1)};
      res.emplace_back(std::move(tmp));
    }
    if (b1 < a1) ++j;
    else ++i;
  }
  return res;
}

int main()
{
  vector<vector<int> > a = {
    {0, 2},
    {5, 10},
    {13, 23},
    {24, 25}
  };

  vector<vector<int> > b = {
    {1, 5},
    {8, 12},
    {15, 24},
    {25, 26}
  };
  auto res = Intersection(a, b);
  printf("[");
  for (int i=0; i < res.size(); ++i) {
    printf("\033[32m[%d %d]\033[0m", res[i][0], res[i][1]);
  }
  printf("]\n");
  return 0;
}


