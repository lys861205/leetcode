/*
 * 归并排序
*/

/*
void mergeSort(一个数组)
{
  if (可以很容易处理) return;
  mergeSort(左半个数组);
  mergeSort(右半个数组);
  merge(左半个数组， 右半个数组);
}
*/
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> aux;

void merge(vector<int>& nums, int lo, int mid, int hi)
{
  int i = lo, j = mid + 1;
  for (int k=lo; k <= hi; ++k) {
    aux[k] = nums[k];
  }
  for (int k=lo; k <= hi; ++k) {
    if (i > mid)  nums[k] = aux[j++];
    else if (j > hi)  nums[k] = aux[i++];
    else if (aux[j] < aux[i])  nums[k] = aux[j++];
    else nums[k] = aux[i++];
  }
}

void mergeSort(vector<int>& nums, int lo, int hi)
{
  
  if (lo>=hi) return ;
  int mid = lo + (hi-lo)/2;
  mergeSort(nums, lo, mid);
  mergeSort(nums, mid+1, hi);
  merge(nums, lo, mid, hi);
}

int main()
{
  vector<int> nums = {3, 8, 9, 2, 4, 1, 5};
  aux.resize(nums.size());
  mergeSort(nums, 0, 6);
  for (int i=0; i < nums.size(); ++i) {
    printf("%d ", nums[i]);
  }
  printf("\n");
  return 0;
}

