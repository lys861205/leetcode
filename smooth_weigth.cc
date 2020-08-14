#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>

class Server {
public:
  Server(const std::string& ip, int weight):ip_(ip), weight_(weight), dynamic_weigth_(weight){}

  const std::string& GetIP() const 
  {
    return ip_;
  }
  
  int GetWeight() const 
  {
    return weight_;
  }

  int GetDynamicWeight() const 
  {
    return dynamic_weigth_;
  }

  void Sub(int weight)
  {
    dynamic_weigth_ -= weight;
  }
  
  void Update() 
  {
    dynamic_weigth_ += weight_;
  }

  bool operator <(const Server& other) const
  {
    return dynamic_weigth_ <= other.dynamic_weigth_ ? false : true;
  }
  
private:
  std::string ip_;
  int  weight_;
  int  dynamic_weigth_;
};

class Servers {
public:
  Servers() 
  {
    servers_.push_back(Server("10.134.57.112", 5));
    servers_.push_back(Server("10.139.48.96", 1));
    servers_.push_back(Server("10.139.20.110", 1));
  }

  void Add(const Server& server)
  {
    servers_.push_back(server);
  }

  void Done()
  {
    std::sort(servers_.begin(), servers_.end());
  }

  int SumWeight() 
  {
    int sum = 0;
    std::vector<Server>::iterator it = servers_.begin();
    for (; it != servers_.end(); ++it) {
      sum += (*it).GetWeight();
    }
    return sum;
  }

  Server Pick()
  {
    int sum = SumWeight();

    std::vector<Server>::iterator it = servers_.begin();
    Server dummy(*it);
    
    //权重最高的减去权重总和
    (*it).Sub(sum);

    for (; it != servers_.end(); ++it) {
      (*it).Update();
    }
    std::sort(servers_.begin(), servers_.end());

    return dummy;
  }

private:
  std::vector<Server> servers_;
};

class SmoothWeight {
public:
  SmoothWeight(){}

  std::string GetConnect() 
  {
    Server s = servers_.Pick();
    return s.GetIP();
  }

private:
  Servers servers_;
};

int main()
{
  SmoothWeight smooth;
  for (int i=1; i < 100; ++i) {
    std::cout << "Server: " << i << " 次 " << smooth.GetConnect() << std::endl;
    if (i%7 == 0) {
      std::cout << "新开始" << std::endl;
    }
    sleep(2);
  }
  return 0;
}



