/*
 * 矩阵查找数据, 矩阵的行是升序排序, 列也是升序排序
*/


#include <vector>
#include <iostream>

using namespace std;

vector<int> search_matrix(vector<vector<int> >& matrix, int target)
{
  int row = 0;
  int col = matrix[0].size() - 1;
  while (row < matrix.size() && col >= 0)
  {
    if (matrix[row][col] == target) {
      return {row, col};
    }
    else if (matrix[row][col] > target) {
      --col;
    }
    else if (matrix[row][col] < target) {
      ++row;
    }
  }
  return {-1, -1};
}

int main()
{
  vector<vector<int> > matrix = {
    {15, 20, 40, 85},
    {20, 35, 80, 95},
    {30, 55, 95, 105},
    {40, 80, 100, 120}
  };
  {
    auto res = search_matrix(matrix, 55);
    std::cout << "[" << res[0] << "," << res[1] << "]" << std::endl;
  }
  {
    auto res = search_matrix(matrix, 120);
    std::cout << "[" << res[0] << "," << res[1] << "]" << std::endl;
  }
  {
    auto res = search_matrix(matrix, 96);
    std::cout << "[" << res[0] << "," << res[1] << "]" << std::endl;
  }
  return 0;
}
