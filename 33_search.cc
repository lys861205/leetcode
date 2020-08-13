/*
 * 搜索旋转排序数组
*/

#include <stdio.h>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target)
{
  int n = nums.size();
  int l = 0, r = n -1;
  while (l <= r) {
    int mid = (l+r)/2;
    if (nums[mid] == target) {
      return mid;
    }
    if (nums[0] <= nums[mid]) {
      if (nums[0] <= target && target <= nums[mid]) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    else {
      if (nums[mid] <= target && target <= nums[n-1]) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
  }
  return -1;
}

int main()
{
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  printf("%d\n", search(nums, 4));
  printf("%d\n", search(nums, 7));
  printf("%d\n", search(nums, 0));
  printf("%d\n", search(nums, 8));
  return 0;
}
