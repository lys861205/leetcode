/*
 * 查找超过一半的数字
*/

#include <vector>
#include <iostream>

using namespace std;

int moreHalfNumber(vector<int>& nums)
{
  if (nums.size() <= 0) {
    return -1;
  }
  int cnt = 0;
  int number = 0;
  for (int i=0; i < nums.size(); ++i) {
    if (cnt==0) {
      number = nums[i];
      cnt++;
    }
    else if (nums[i] == number) {
      cnt++;
    } else {
      cnt--;
    }
  }
  int n = 0;
  for (int i=0; i < nums.size() && cnt; ++i) {
    if (nums[i] == number) {
      ++n; 
    }
  }
  if (n > nums.size()/2) {
    return number;
  }
  else {
    return -1;
  }
}

int main()
{
  vector<int> nums = {
    1, 6, 3, 4, 7, 5, 2
  };
  vector<int> nums1 = {
    1,  2, 2, 2, 4, 4, 4, 3, 2, 2, 2, 4
  };
  std::cout << moreHalfNumber(nums) << std::endl;
  std::cout << moreHalfNumber(nums1) << std::endl;
  return 0;
}
