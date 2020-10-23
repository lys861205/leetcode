#include <string>

using namespace std;

// main的长度 n; pattern 长度 m

// 暴力匹配，时间复杂度 O(n*m)
int BFMatch(const string& main, const string& pattern)
{
  return 0;
}

// 时间复杂度O(m)
// 算法主要是找
// 1 坏字符
// 2 好后缀 (本代码未实现)
// 看谁移动更远，就是使用谁的移动距离
int BMMatch(const string& main, const string& pattern)
{
  int n = main.size();
  int m = pattern.size();
  if (n < m) {
    return -1;
  }
  //从右往左比较
  int endPos = pattern.size() - 1;
  while (endPos < main.size()) {
    m = pattern.size() - 1;
    n = endPos;
    while (main[n] == pattern[m] && m>=0) { //从右向左进行匹配
      --m;
      --n;
    }
    if (m < 0) { // 匹配成功
      return endPos - pattern.size() + 1;
    }
    while (m>=0) {  // 从模式串中查找与n相等的坏字符
      if (pattern[m] == main[n]) { 
        endPos = n + (pattern.size() - m - 1);
        break;  
      }
      --m;
    }
    if (m < 0) { //模式串中为找到坏字符串，往主串之后移动m距离
      endPos += pattern.size();
    }
  }
  return -1;
}

int RKMatch(const string& main, const string& pattern)
{
  return -1;
}

int KMPMatch(const string& main, const string& pattern)
{
  return -1;
}

int main()
{
  const string main = "GTTATAGCTGGTAGCGGCGAA";
  const string pattern = "GTAGCGGCG";
  const string pattern1 = "CGGCGAA";
  printf("%d\n", BMMatch(main, pattern));
  printf("%d\n", BMMatch(main, pattern1));
  return 0;
}
