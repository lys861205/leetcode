#include <stdio.h>
#include <vector>

using namespace std;

int findPeak(vector<int>& nums)
{
  for (size_t i=0; i < nums.size()-1; ++i) {
    if (nums[i] > nums[i+1]) {
      return i;
    }
  }
  return nums.size()-1;
}

int main()
{
  vector<int> nums = {1, 2, 3, 1};
  printf("%d\n", findPeak(nums));
  return 0;
}
