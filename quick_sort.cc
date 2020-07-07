/*
 * 快速排序
*/
#include <stdio.h>
#include <vector>
using namespace std;

void QuickSort(vector<int>& nums, int l, int r)
{
  int low = l;
  int high = r;
  if (low < high) {
    int pivot = nums[low]; 
    while (low < high) {
      while (low < high && nums[high] >= pivot) {
        --high;
      }
      nums[low] = nums[high];
      while (low < high && nums[low] <= pivot) {
        ++low;
      }
      nums[high] = nums[low];
    }
    nums[low] = pivot;
    QuickSort(nums, l, low-1);
    QuickSort(nums, low+1, r);
  }
}

int main()
{
  vector<int> nums = {9, 2, 8, 3, 5, 6, 7, 4, 1, 0};
  QuickSort(nums, 0, nums.size()-1);
  for (int i=0; i < nums.size(); ++i) {
    printf("%d ", nums[i]);
  }
  printf("\n");
  return 0;
}
