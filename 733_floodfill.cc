/*
 * 图像渲染
*/

#include <stdio.h>
#include <vector>

using namespace std;

bool inArea(vector<vector<int> >& image, int x, int y)
{
  return (x >= image.size() || y >= image[0].size()) ? false : true;
}

void fill(vector<vector<int> >& image, int x, int y, int origColor, int newColor)
{
  //出界
  if (!inArea(image, x, y)) return ;
  //碰壁 遇到其他颜色
  if (image[x][y] != origColor) return;
  image[x][y] = newColor;

  fill(image, x-1, y, origColor, newColor);
  fill(image, x+1, y, origColor, newColor);
  fill(image, x, y-1, origColor, newColor);
  fill(image, x, y+1, origColor, newColor);
}

vector<vector<int> > FloodFill(vector<vector<int> >& image, int sr, int sc, int newColor)
{
  int origColor = image[sr][sc];
  if (origColor != newColor) {
    fill(image, sr, sc, origColor, newColor);
  }
  return image;
}

int main()
{
  vector<vector<int> > image = {
    {1, 1, 1, 1},
    {1, 1, 0, 1},
    {1, 0, 1, 1}
  };
  image = FloodFill(image, 1, 1, 2); 
  for (int i=0; i < image.size(); ++i) {
    for (int j=0; j < image[i].size();++j) {
      printf("%d ", image[i][j]);
    }
    printf("\n");
  }
  return 0;
}
