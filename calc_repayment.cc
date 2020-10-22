#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 #include <ctype.h>

float total_pay = 0.0;
void CalcPayment(float mount, float rate, int cnt, int year)
{
  static int p = 1;
  if (cnt <= 0) {
    return;
  }
  if (p) {
    printf("贷款总额:%0.2f, 还款年限：%d 年， 利率：%.2f%\n", mount, cnt, rate*100);
    p = 0;
  }
  mount = mount*(1+rate);
  float pay = (float)mount / cnt;
  printf("第 %d 年需要还款 %.2f\n", year, pay);
  mount -= pay;
  total_pay += pay;
  CalcPayment(mount, rate, cnt-1, year+1);
}

float GetRate(int n) 
{
  if (n <= 1) {
    return 4.35/100;
  } else if (n <= 5) {
    return 4.75/100;
  } else {
    return 4.90/100;
  }
}

int main(int argc, char** argv)
{
  
  float money = 100000.0;
  float rate  = 0.0475;
  int cnt = 3;
  int c = 0;
  while ((c = getopt(argc, argv, "m:n:h")) != -1) {
    switch (c) {
      case 'm':
      sscanf(optarg, "%f", &money);
      break;
      // case 'r':
      // sscanf(optarg, "%f", &rate);
      // rate = rate/100;
      break;
      case 'n':
      sscanf(optarg, "%d", &cnt);
      break;
      case 'h':
      fprintf(stderr, "\033[31mUsage: calc_repayment [options]\n"
                       "Options are:\n"
                       "[ -m money ] [ -n years ]\033[0m\n");
      exit(1);
      default:
      fprintf(stderr, "invalid option -- '%c'\n", c);
      exit(1);
    }
  }
  rate = GetRate(cnt);
  CalcPayment(money, rate, cnt, 1);
  printf("总还款: %0.2f, 利息总额: %0.2f\n", total_pay, total_pay - money);
  return 0;
}

