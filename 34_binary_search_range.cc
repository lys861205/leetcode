/*
 * 在排序数组中查找元素第一个和最后一个元素的位置
*/

#include <vector>
#include <stdio.h>

using namespace std;

int left_bound(vector<int>& nums, int target) 
{
  int left = 0;
  int right = nums.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
      right = mid - 1;
    }
    else if (nums[mid] > target) {
      right = mid - 1;
    }
    else if (nums[mid] < target) {
      left = mid + 1;
    }
  }
  return (left >= nums.size() || nums[left] != target) ? -1 : left;
}

int right_bound(vector<int>& nums, int target)
{
  int left = 0;
  int right = nums.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
      left = mid + 1;
    }
    else if (nums[mid] > target) {
      right = mid - 1;
    }
    else if (nums[mid] < target) {
      left = mid + 1;
    }
  }
  return (right < 0 || nums[right] != target) ? -1 : right;
}

vector<int> search_range(vector<int>& nums, int target)
{
  return { left_bound(nums, target),
           right_bound(nums, target)};
}

int main()
{
  vector<int> nums = {
    5,7,7,8,8,10
  };
  auto res = search_range(nums, 8);
  printf("[%d %d]\n", res[0], res[1]);

  res = search_range(nums, 6);
  printf("[%d %d]\n", res[0], res[1]);

  return 0;
}
