#include <iostream>

using namespace std;


class Base 
{
public:
  Base(int v):a_(v){}
  ~Base(){}
  virtual void test() {std::cout << "test" << std::endl;}
  virtual void test1() {std::cout << "test1" << std::endl;}
  void print() {}
private:
  int a_;
};

class Derive : public Base {
public:
  Derive(int v):Base(v+100), b_(v) {}
private:
  int b_;
};

int main()
{
  std::cout << sizeof(Base) << std::endl;
  Base b(100);
  typedef void(*Fun)(void);
  Fun f = (Fun)*((int*)*(int*)(&b)+0);
  f();

  std::cout << sizeof(b) << std::endl;

  Derive d(200);
  d.test();
  return 0;
}
