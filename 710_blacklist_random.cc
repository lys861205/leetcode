#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Solution {
public:
  Solution(int N, vector<int>& blacklist) 
  {
    unordered_map<int, int> hash;
    for (auto& e : blacklist) {
      hash[e] = 1; 
    }
    //有效数据的大小
    sz_ = N - blacklist.size(); 
    //最后元素的索引
    int last = N - 1;
    for (auto& e : blacklist) {
      if (e > sz_) { // 该黑名单已经在后面，不需要移动了
        continue; 
      }
      //判断last索引处的值是不是黑名单
      while (hash.count(last)) { //直到找到一个非黑名单的值
        --last; 
      }
      black_white_hash_[e] = last;
      --last;
    }
  }

  int Pick() 
  {
    int index = rand() % sz_;
    if (black_white_hash_.count(index)) {
      return black_white_hash_[index];
    }
    return index;
  }
private:
  unordered_map<int, int> black_white_hash_;
  int sz_;
};

int main()
{
  srand(time(NULL));
  vector<int> blacklist = {1, 4, 2, 3, 8}; 
  Solution s(20, blacklist);
  for (int i=0; i < 10; ++i) {
    printf("PICK %d\n", s.Pick());
  }
  return 0;
}
