/*
 * 搜索旋转数组
*/

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int l, int r, int target)
{
  if (l > r) return -1;
  int mid = l + (r-l)/2;
  if (nums[mid] == target) {
    return mid;
  }
  if (nums[l] < nums[mid]) { //左边是有序的
    if (target >= nums[l] && target < nums[mid]) {
      return search(nums, l, mid-1, target);
    }
    else {
      return search(nums, mid+1, r, target);
    }
  }
  else if (nums[mid] < nums[r]) { //右边有序
    if (target <= nums[r] && target > nums[mid]) {
      return search(nums, mid+1, r, target);
    }
    else {
      return search(nums, l, mid-1, target);
    }
  }
  return -1;
}

int main()
{
  vector<int> nums = {
   50, 5, 20, 30, 40
  };
  int l = 0;
  int r = nums.size() - 1;
  std::cout << search(nums, l, r, 30) << std::endl;
  return 0;
}
