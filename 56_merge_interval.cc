#include <vector>
#include <stdio.h>
#include <tuple>

using namespace std;

typedef vector<tuple<int, int> > VecTuple;


VecTuple merge(VecTuple& tuples)
{
  VecTuple res;
  if (tuples.size() <= 0) {
    return res;
  }
  res.push_back(tuples[0]);
  int start, end;
  for (int i=1; i < tuples.size(); ++i) {
    tuple<int, int>& curr = tuples[i]; 
    tuple<int, int>& prev = res.back();
    if (std::get<0>(curr) < std::get<1>(prev)) {
      end = std::max(std::get<1>(curr), std::get<1>(prev));
      std::get<1>(prev) = end;
    }else {
      res.push_back(curr);
    }
  }
  return res;
}

vector<vector<int> > merge2(vector<vector<int> >& nums)
{
  vector<vector<int> > res;
  if (nums.size() <= 0) {
    return res;
  }
  res.push_back(nums[0]);
  for (int i=1; i < nums.size(); ++i) {
    vector<int>& cur  = nums[i];
    vector<int>& prev = res.back();
    if (cur[0] < prev[1]) {
      prev[1] = std::max(cur[1], prev[1]);
    } else {
      res.push_back(cur);
    }
  }
  return res;
}


int main()
{
  VecTuple tuples = {
    make_tuple(1, 3),
    make_tuple(2, 6),
    make_tuple(8, 10),
    make_tuple(15, 18)
  };

  auto res = merge(tuples);
  printf("[ ");
  for (int i=0; i < res.size(); ++i) {
    tuple<int, int>& tmp = res[i];
    printf("[%d %d] ", std::get<0>(tmp), std::get<1>(tmp));
  }
  printf("]\n");
  printf("====================\n");
  vector<vector<int> > nums = {
    {1, 3},
    {2, 6},
    {8, 10},
    {15, 18}
  };
  vector<vector<int> > res2 = merge2(nums);
  printf("[ ");
  for (int i=0; i < res2.size(); ++i) {
    printf("[%d %d] ", res2[i][0], res2[i][1]);
  }
  printf("]\n");
  return 0;
}


