/*
 * 二分查找
*/

#include <vector>
#include <stdio.h>

using namespace std;

int binary_search(vector<int>& nums, int target)
{
  int left = 0;
  int right = nums.size() - 1;

  while (left <= right) {
    int mid = left + (right - left)/2;
    if (nums[mid] == target) {
      return mid;
    } else if (nums[mid] > target) {
      right = mid - 1;
    } else if (nums[mid] < target) {
      left = mid + 1;
    }
  }
  return -1;
}

int main()
{
  vector<int> nums = {-1, 0, 3, 5, 9, 12};
  printf("%d\n", binary_search(nums, 9));
  return 0;
}
