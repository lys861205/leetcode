#include <stdio.h>
#include "Tree.h"
#include <vector>
#include <limits.h>

using namespace std;

int GetMaxValueIndex(const vector<int>& nums) 
{
  if (nums.size() <= 0) {
    return -1;
  }
  int index = 0;
  int MaxValue = nums[0];
  for (int i=1; i < nums.size(); ++i) {
    if (MaxValue < nums[i]) {
      index = i;
      MaxValue = nums[i];
    }
  }
  return index;
}

Tree* build(const vector<int>& nums, int lo, int hi)
{
  if (lo >= hi) {
    return nullptr;
  }
  int index = lo;
  int MaxValue = INT_MIN;
  for (int i=lo; i < hi; ++i) {
    if (nums[i] > MaxValue) {
      MaxValue = nums[i];
      index = i;
    }
  }
  Tree* root = BSTCreate(MaxValue);
  root->left = build(nums, lo, index);
  root->right = build(nums, index+1, hi);
  return root;
}

Tree* ConstructMaxTree(const vector<int>& nums)
{
  return build(nums, 0, nums.size());
  /*
  int i = GetMaxValueIndex(nums);
  if (i == -1) {
    return nullptr;
  }
  Tree* root = BSTCreate(nums[i]);
  std::vector<int> l_vector;
  std::vector<int> r_vector;
  std::copy(nums.begin(), nums.begin()+i, std::back_inserter(l_vector));
  std::copy(nums.begin()+i+1, nums.end(), std::back_inserter(r_vector));
  root->left  = ConstructMaxTree(l_vector);
  root->right = ConstructMaxTree(r_vector);
  return root;
  */
}

int main()
{
  vector<int> nums = {3, 2, 1, 6, 0, 5}; 
  Tree* root = ConstructMaxTree(nums);
  Print(root, 3, '*');
  return 0;
}
