/*
 * N 皇后排列的问题
*/

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

vector<vector<string> > res;

bool isValid(vector<string>& board, int row, int col);
void backtrack(vector<string>& board, int row);

vector<vector<string> > sloveNQueens(int n)
{
  vector<string> board(n, string(n, '0'));
  backtrack(board, 0);
  return res;
}


void backtrack(vector<string>& board, int row)
{
  if (board.size() == row) {
    res.push_back(board);
    return;
  }
  int n = board[row].size();
  for (int col = 0; col < n; ++col) {
    if (!isValid(board, row, col)) {
      continue;
    }
    board[row][col] = '1';
    backtrack(board, row+1);
    board[row][col] = '0';
  }
}

bool isValid(vector<string>& board, int row, int col)
{
  int n = board.size();
  //列
  for (int i = 0; i < n; ++i) {
    if (board[i][col] == '1') {
      return false;
    }
  }
  // 左上方
  for (int i=row-1, j=col-1; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j] == '1') {
      return false;
    }
  }
  //右上方
  for (int i=row-1, j=col+1; i >= 0 && j < n; i--, j++) {
    if (board[i][j] == '1') {
      return false;
    }
  }
  return true;
}

int main()
{
  vector<vector<string> > vec = sloveNQueens(8);
  for (size_t i=0; i < vec.size(); ++i) {
    printf("\n");
    for (size_t j=0; j < vec[i].size(); ++j) {
      printf("%s\n", vec[i][j].c_str());
    }
  }
  return 0;
}

