/*
 * 读取文件最后k行内容
*/

#include <string>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;


const int K = 10;

void lastKlines(const string& filename, vector<string>& lines)
{
  ifstream fp(filename);
  int size = 0;
  while (fp.peek() != EOF) {
    string& line = lines[size % K];
    getline(fp, line);
    ++size;
  }
  fp.close();

  int start = size > K ? size % K : 0;
  int count = min(K, size);

  for (int i=0; i < count; ++i) {
    std::cout << "\033[32mcount_down: " << (count - i)  << "\033[0m" << lines[(start+i)%K] << std::endl; 
  }
}

int main()
{
  vector<string> lines(K);
  lastKlines("./k_line_file.cc", lines);
  return 0;
}


