#include <stdio.h>
#include <vector>
#include <algorithm> 

using namespace std;

struct Point
{
  Point(int x, int y):x(x), y(y){}
  int x;
  int y;
  bool operator<(const Point& p) const
  {
    if ( x < p.x || (x == p.x && y > p.y) ) {
      return true;
    }
    return false;
  }
};

int MaxEnvepoles(vector<Point>& envepoles)
{
  std::sort(envepoles.begin(), envepoles.end());
  int max = 0;
  vector<int> dp(envepoles.size(), 1);
  for (int i=1; i < envepoles.size(); ++i) {
    Point& p = envepoles[i];
    for (int j=0; j < i; ++j) {
      Point& p1 = envepoles[j];
      if (p.y > p1.y) {
        dp[i] = std::max(dp[j]+1, dp[i]);
      }
    }
    if (dp[i] > max) {
      max = dp[i];
    }
  }
  return max;
}

int main()
{
  vector<Point> envepoles = {
    {5, 4},
    {6, 4},
    {6, 7},
    {2, 3}
  };
  printf("%d\n", MaxEnvepoles(envepoles));
  return 0;
}
