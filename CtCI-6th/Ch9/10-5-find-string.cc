/*
 * 稀疏数组搜索。有个排好序的字符串数组，其中散布着一些空字符串，编写一种方
 * 法，找出给定字符串的位置
*/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int search(vector<string>& strs, string& str, int l, int r)
{
  if (l > r) return -1;
  int mid = l + (r-l)/2;
  if (strs[mid] == str) {
    return mid;
  }
  if (strs[mid] == "") {
    int left = mid - 1;
    int right = mid + 1;
    while (1) {
      if (left < l && right > r) {
        return -1;
      }
      else if (left >= l && strs[left] != "") {
        mid = left;
        break;
      }
      else if (right <= r && strs[right] != "") {
        mid = right;
        break;
      }
      ++right;
      --left;
    }
  }
  if (strs[mid] == str) {
    return mid;
  }
  if (strs[mid].compare(str) > 0) {
    return search(strs, str, l, mid);
  } else {
    return search(strs, str, mid, r);
  }
}

int main()
{
  vector<string> strs = {
    "at", "", "", "", "ball", "", "", "car", "", "", "dad",
    "", ""
  };
  string s = "ball";
  std::cout << search(strs, s, 0, strs.size()-1) << std::endl;
  return 0;
}
