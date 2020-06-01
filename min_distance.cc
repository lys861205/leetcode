#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int minDistance(string s1, string s2, int s1_pos, int s2_pos)
{
  if (s1_pos == -1) return s2_pos + 1;
  if (s2_pos == -1) return s1_pos + 1;

  if (s1[s1_pos] == s2[s2_pos]) {
    return minDistance(s1, s2, s1_pos - 1, s2_pos - 1);
  }
  else {
    int minOp = min(minDistance(s1, s2, s1_pos, s2_pos-1)+1,
                    minDistance(s1, s2, s1_pos-1, s2_pos)+1);
    minOp = min(minOp, minDistance(s1, s2, s1_pos-1, s2_pos-1)+1);
    return minOp;
  }
}

int main()
{
  string s1 = "horse";
  string s2 = "ros";
  printf("%d\n", minDistance(s1, s2, s1.size()-1, s2.size()-1));
  return 0;
}
