#include <stdio.h>
#include <vector>
#include <set>
#include <string>

using namespace std;

bool backstrace(vector<vector<char> >& board, const string& word, int pos, int x, int y);

bool IsFound(vector<vector<char> > board, const string& word)
{
  for (size_t i = 0; i < board.size(); ++i) {
    for (size_t j = 0; j < board[i].size(); ++j) {
      if (backstrace(board, word, 0, i, j)) {
        //printf("\n");
        return true;
      }
      //printf("\n");
    }
  }
}

bool backstrace(vector<vector<char> >& board, const string& word, int pos, int x, int y)
{
  //printf("%c", board[x][y]);
  if (word[pos] != board[x][y]) {
    return false;
  }
  //printf("%c", board[x][y]);
  if (word.size()-1 == pos) {
    return true;
  }
  ++pos;
  char  tmp = board[x][y];
  board[x][y] = 0;
  if (x>0 && backstrace(board, word, pos, x-1, y)) { //往上走
    return true;
  }
  else if (y >0 && backstrace(board, word, pos, x, y-1)) { //往左走
    return true;
  }
  else if (x < (board.size()-1) && backstrace(board, word, pos, x+1, y)) { //往下走
    return true;
  }
  else if (y < (board[x].size()-1) && backstrace(board, word, pos, x, y+1)) { //往右走
    return true;
  }
  else {
    board[x][y] = tmp;
  }
  return false;
}

int main()
{
  vector<vector<char> > board = {
  {'A', 'B', 'C', 'E'},
  {'S', 'F', 'C', 'S'},
  {'A', 'D', 'E', 'E'}
  };
  printf("%d\n", IsFound(board, "ABCCED"));
  printf("%d\n", IsFound(board, "SEE"));
  printf("%d\n", IsFound(board, "ABCC"));
  return 0;
}
