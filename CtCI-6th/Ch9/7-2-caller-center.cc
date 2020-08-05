/*
 * 呼叫中心
*/

class Emp {
public:
  Emp(){}
  virtual ~Emp(){}

  virtual void Do() = 0;

};

class Telephone : public Emp {
public:
  Telephone(){}
  ~Telephone(){}

  virtual void Do()
  {
  }
};

class Master : public Emp {
public:
  Master(){}
  ~Master(){}
  
  virtual void Do()
  {
  }
};

class Manager : public Emp {
public:
  Manager(){}
  ~Manager(){}

  virtual void Do()
  {
  }
};


class CalleeCenter {
public:
  CalleeCenter(){}
  ~CalleeCenter(){}
  
  void Dipatch()
  {
  }

};

int main()
{
  return 0; 
}
