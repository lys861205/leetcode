/*
 * 矩阵旋转90度
*/

#include <vector>
#include <stdio.h>

using namespace std;

void RotateMatrix(vector<vector<int> >& matrix, int M, int N)
{
  for (int i=0; i < M/2; ++i) {
    for (int j=i; j < N-i-1; ++j) {
      int temp =  matrix[i][j];
      matrix[i][j] = matrix[N-i-1][N-j-1];
      matrix[N-i-1][N-j-1] = matrix[N-j-1][i];
      matrix[N-j-1][i] = temp;
    }
  }
}

int main()
{
  vector<vector<int> > matrix = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8}
  };
  RotateMatrix(matrix, 3, 3);
  for (int i=0; i < matrix.size(); ++i) {
    for (int j=0; j < matrix[i].size(); ++j) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  return 0;
}
