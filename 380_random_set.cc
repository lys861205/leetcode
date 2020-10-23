#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <time.h>
#include <stdlib.h>

using namespace std;

class RandomSet {
public:
  bool Remove(int value) 
  {
    if (!value_index_.count(value)) { //元素不存在
      return false;
    }
    //获取删除元素的索引
    int index = value_index_[value];
  
    // 更新最后一个元素的索引 
    value_index_[nums_.back()] = index;
    // 交换删除元素和最后一个元素位置
    swap(nums_[index], nums_.back());

    // 删除最后一个元素
    nums_.pop_back();

    // 删除 删除元素对应的索引
    value_index_.erase(value);
    return true;
  }
  bool Insert(int value) 
  {
    if (value_index_.count(value)) {
      return false;
    }
    value_index_[value] = nums_.size();
    nums_.push_back(value);
    return true;
  }
  int Random() const 
  {
    return nums_[rand() % nums_.size()];
  }
private:
  vector<int> nums_;
  unordered_map<int, int> value_index_;
};

int main()
{
  srand(time(NULL));
  RandomSet rs;
  
  for (int i=0; i < 10; ++i) {
    printf("Insert %d is %s\n", i, rs.Insert(i) ? "Success" : "Failed");
  }
  rs.Remove(9);
  rs.Remove(8);
  rs.Remove(7);
  for (int i=0; i < 10; ++i) {
    printf("Get random value: %d\n", rs.Random());
  }
  return 0;
}
