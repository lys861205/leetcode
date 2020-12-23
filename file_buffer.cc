#include<stdio.h>
#include<unistd.h>
int main(void)
{
  {
    setbuf(stdout,NULL);
    printf("bianchengzhuji");
    sleep(5);
  }
  {
    char buf[BUFSIZ] = {0};
    setbuf(stdout, buf);
    printf("bianchengzhuji");
    sleep(5);
  }
  return 0;
}
