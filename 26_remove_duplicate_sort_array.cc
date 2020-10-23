#include <stdio.h>
#include <vector>

using namespace std;

int RemoveDuplicate(vector<int>& nums)
{
  int p = 0;
  int c = 0;
  while (c < nums.size()) {
    if (nums[p] != nums[c]) {
      ++p;
      nums[p] = nums[c];
    }
    ++c;
  }
  nums.resize(p+1);
  return p+1;
}

int main()
{
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int size = RemoveDuplicate(nums);
  for (int i=0; i < size; ++i) {
    printf("%d ", nums[i]); 
  }
  printf("\n");
  return 0;
}
