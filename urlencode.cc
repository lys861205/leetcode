#include <stdio.h>
#include <string>

using namespace std;

string urldecode(const string& url)
{
  char buf[1024] = {0};
  int idx = 0;
  for (int i=0; i < url.size(); ++i) {
    if (url[i] == '%') {
      char hi = url[i+1];
      hi = hi < 'A' ? hi - '0' : toupper(hi) - 'A' + 10;
      char lo = url[i+2];
      lo = lo < 'A' ? lo - '0' : toupper(lo) - 'A' + 10;
      buf[idx] = (hi << 4) +  (lo & 0x0f);
      i += 2;
    }else {
      buf[idx] = url[i];
    }
    ++idx;
  }
  return string(buf);
}

int main()
{
  printf("%s\n", urldecode("%e6%89%8b%e6%9c%ba").c_str());
  printf("%s\n", urldecode("%e8%be%93%e5%85%a5%e6%b3%95").c_str());
  return 0;
}
