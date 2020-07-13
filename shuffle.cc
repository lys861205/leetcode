/*
 * 洗扑克牌
*/
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void shuffle(vector<char>& cards)
{
  int n = cards.size();
  for (int i=0; i < n; ++i)
  {
    int r = i+rand()%(n-i);
    swap(cards[i], cards[r]);
  }
}

int main()
{
  srand(time(NULL));
  vector<char> cards = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'J', 'Q', 'K'};
  shuffle(cards);
  for (int i=0; i < cards.size(); ++i) {
    printf("%c ", cards[i]);
  }
  printf("\n");
  return 0;
}
