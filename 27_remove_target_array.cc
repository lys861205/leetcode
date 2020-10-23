#include <stdio.h>
#include <vector>

using namespace std;


int RemoveElement(vector<int>& nums, int target)
{
  int p=0, c=0;
  while (c < nums.size()) {
    if (nums[c] != target) {
      nums[p] = nums[c];
      ++p;
    }
    ++c;
  }
  nums.resize(p);
  return p;
}

int main()
{
  {
    vector<int> nums = {3, 2, 2, 3};
    int size = RemoveElement(nums, 3);
    for (int i=0; i < size; ++i) {
      printf("%d ", nums[i]);
    }
    printf("\n");
  }

  {
    vector<int> nums = {3, 3, 3, 3};
    int size = RemoveElement(nums, 3);
    for (int i=0; i < size; ++i) {
      printf("%d ", nums[i]);
    }
    printf("\n");
  }

  {
    vector<int> nums = {3, 3, 3, 3};
    int size = RemoveElement(nums, 2);
    for (int i=0; i < size; ++i) {
      printf("%d ", nums[i]);
    }
    printf("\n");
  }
  return 0;
}
