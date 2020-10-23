#include <stdio.h>
#include <vector>

using namespace std;

void MoveZero(vector<int>& nums) 
{
  int p=0, c=0;
  while (c < nums.size()) {
    if (nums[c] != 0) {
      if (p != c) {
        swap(nums[p], nums[c]);
      }
      ++p;
    }
    ++c;
  }
}

int main()
{
  vector<int> nums = {1, 5, 4, 0, 2};
  MoveZero(nums);
  for (int i=0; i < nums.size(); ++i) {
    printf("%d ", nums[i]);
  }
  printf("\n");
  return 0;
}
