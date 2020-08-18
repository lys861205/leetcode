#include <stdio.h>
#include <vector>

using namespace std;

void DFS(vector<vector<char> >& board, int x, int y)
{
  int m = board.size();
  int n = board[0].size();
  if (x < 0 || y < 0 ||  x >= m || y >= n || board[x][y] != 'O') return;
  if (board[x][y] == 'O') {
    board[x][y] = '-';
  }
  DFS(board, x-1, y);
  DFS(board, x+1, y);
  DFS(board, x, y-1);
  DFS(board, x, y+1);
}

void Solve(vector<vector<char> >& board)
{
  int row = board.size();
  int col = board[0].size();
  for (int i=0; i < row; ++i) {
    DFS(board, i, 0);    
    DFS(board, i, col-1);    
  }
  for (int j=0; j < col; ++j) {
    DFS(board, 0, j);    
    DFS(board, row-1, j);    
  }

  for (int i=0; i < row; ++i) {
    for (int j=0; j < col; ++j) {
      if (board[i][j] == 'O') {
        board[i][j] = 'X';
      }
      else if (board[i][j] == '-') {
        board[i][j] = 'O';
      }
    }
  }
}

int main()
{
  vector<vector<char> > board = {
    {'X', 'X', 'X', 'X'},
    {'X', 'O', 'O', 'X'},
    {'X', 'X', 'O', 'X'},
    {'X', 'O', 'X', 'X'}
  };
  Solve(board);
  for (int i=0; i < board.size(); ++i) {
    for (int j=0; j < board[i].size(); ++j) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
  return 0;
}
