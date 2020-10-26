#include <string>
#include <vector>

using namespace std;

// main的长度 n; pattern 长度 m

// 暴力匹配，时间复杂度 O(n*m)
int BFMatch(const string& main, const string& pattern)
{
  if (main.size() < pattern.size()) {
    return -1;
  }
  for (int i=0; i < main.size(); ++i) {
    int sPos = i;
    bool match = true;
    for (int j=0; j < pattern.size() && sPos < main.size(); ++j, sPos++) {
      if (main[sPos] != pattern[j]) {
        match = false;
        break;
      }
    }
    if (match) {
      return i;
    }
  }
  return -1;
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

// Rabin-Karp算法
int Hash(const string& s) 
{
  int hashcode = 0;
  for (auto& c : s) {
    hashcode += c;
  }
  return hashcode;
}
bool MatchOfIndex(int index, const string& main, const string& pattern) 
{
  int j = 0;
  int i = index;
  for (;i < main.size() && j < pattern.size(); ++i, ++j) {
    if (pattern[j] != main[i]) {
      return false;
    } 
  }
  return j == pattern.size() ? true : false;
}
#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

int RKMatch(const string& main, const string& pattern)
{
  if (main.size() < pattern.size()) {
    return -1;
  }
  int m = pattern.size();
  int hash_pattern = Hash(pattern);
  int hash_main    = 0;
  for (int i = 0; i < main.size() && i+m <= main.size(); ++i) {
      if (unlikely(hash_main == 0)) {
        hash_main = Hash(main.substr(0, pattern.size()));
      } else {
        hash_main = hash_main - main[i-1] + main[i+m-1];
      }
      if (hash_main == hash_pattern && MatchOfIndex(i, main, pattern)) {
        return i;
      } 
  }
  return -1;
}

// D.E.Knuth J.H.Morris V.R.Pratt 算法, 简称KMP算法
// 计算模式串部分匹配数组, 动态规划生成
// 字符串匹配数组规则如下：
/*
 * |------------------------|
 * |搜索词    |A B C D A B D|
 * |匹配值长度|0 0 0 0 1 2 0|
 * |------------------------|
 *
 * 部分匹配就是“前缀”和“后缀”的最长共有元素长度，举例:ABCEABD
 * |-----------------------------------------------------------------------------------------|
 * | 字符串  |              前缀集合          |           后缀集合            | 共有元素长度 |
 * | A       |                空              |             空                |     0        |
 * | AB      |                A               |             B                 |     0        |
 * | ABC     |            A, AB               |           BC, C               |     0        |
 * | ABCD    |         A, AB,ABC              |       BCD, CD, D              |     0        |
 * | ABCDA   |         A, AB,ABC, ABCD        |     BCDA, CDA, DA, A          |     1        |
 * | ABCDAB  |    A, AB,ABC, ABCD,ABCDA       |  BCDAB, CDAB, DAB, AB         |     2        |
 * | ABCDABD | A, AB, ABC, ABCD, ABCDA, ABCDAB|BCDABD, CDABD, DABD, ABD, BD, D|     0        |
 * |---------|--------------------------------|-------------------------------|--------------|
 * 因此next数组元素 0, 0, 0, 0, 1, 2, 0
 * next 动态规划求解公式:
 *           |
 *           | next[i-1] + 1 (pattern[i] == pattern[next[i-1]])
 * next[i] = |
 *           | 0             (pattern[i] != pattern[next[i-1]])
 *           |
 *
 * 参考：http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
*/
vector<int> CalcNext(const string& pattern) 
{
  vector<int> next(pattern.size(), 0);
  int m = pattern.size();
  for (int i = 1; i < m; ++i) {
    if (pattern[i] == pattern[next[i-1]]) {
      next[i] = next[i-1] + 1;
    } else {
      next[i] = 0;
    }
  }
  // vector<int> next = {
  //   0, 0, 0, 0, 1, 2, 0
  // };
  return std::move(next);
}
// 时间复杂度O(m+n)
// KMP算法实际是模式串移动位数
// 移动位数 = 已匹配的数量 - 此位置共有元素长度
int KMPMatch(const string& main, const string& pattern)
{
  if (main.size() < pattern.size()) {
    return -1;
  }
  vector<int> nexts = CalcNext(pattern);
  int m = pattern.size();
  for (int i=0; i < main.size();) {
    int move = 1;
    int match_cnt  = 0;
    int n = i;
    for (int j=0; j < pattern.size(); ++j, ++n) {
      if (main[n] == pattern[j]) {
        ++match_cnt; 
      } else {
        break;
      }
    }
    if (match_cnt == m) {
      return i;
    }
    if (match_cnt > 0) {
      move = match_cnt - nexts[match_cnt-1];
      move = move ? move : 1;
    }
    i += move;
  }
  return -1;
}

int main()
{
  const string main = "GTTATAGCTGGTAGCGGCGAA";
  const string pattern = "GTAGCGGCG";
  const string pattern1 = "CGGCGAA";
  printf("%d\n", BMMatch(main, pattern));
  printf("%d\n", BFMatch(main, pattern));
  printf("%d\n", RKMatch(main, pattern));

  printf("%d\n", BMMatch(main, pattern1));
  printf("%d\n", BFMatch(main, pattern1));
  printf("%d\n", RKMatch(main, pattern1));
  {
    const string kmp_str = "BBC ABCDAB ABCDABCDABDE";
    const string kmp_pattern = "ABCDABD";
    printf("%d\n", KMPMatch(kmp_str, kmp_pattern));
    printf("%d\n", BMMatch(kmp_str, kmp_pattern));
  }
  return 0;
}
