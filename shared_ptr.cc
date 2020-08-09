#include <iostream>

class shared_count {
public:
  shared_count():count_(0) 
  {
  }

  int add_ref() 
  {
    return count_++;
  }

  int sub_ref() 
  {
    count_--;
    return count_;
  }

  int use_count()
  {
    return count_;
  }
private:
  int count_;
};

template<class T>
class shared_ptr
{
  typedef T* pointer_t;
  typedef T& reference_t;

public:
  shared_ptr(T* p):ptr_(p)
  {
    std::cout << "shared_ptr ator " << std::endl;
    pn_ = new shared_count(); 
    pn_->add_ref();
  }
  ~shared_ptr() 
  {
    std::cout << "shared_ptr dtor " << std::endl;
    if (pn_ && 0 == pn_->sub_ref()) {
      std::cout << "delete memory" << std::endl;
      delete ptr_;
      std::cout << "delete referenct counter" << std::endl;
      delete pn_;
    }
  }

  shared_ptr(const shared_ptr& rh) 
  {
    std::cout << "copy ator" << std::endl;
    ptr_ = rh.ptr_;
    pn_ =  rh.pn_;
    pn_->add_ref();
  }

  shared_ptr& operator=(const shared_ptr& rh)
  {
    std::cout << "assign ator" << std::endl;
    if (*this == rh) return *this;
    ptr_ = rh.ptr_;
    pn_ =  rh.pn_;
    pn_->add_ref();
    return *this;
  }
  
  int use_count() const
  {
    if (pn_) {
      return pn_->use_count();
    }
    return 0;
  }

  pointer_t get() const 
  {
    return ptr_;
  }

  pointer_t operator->() const 
  {
    return ptr_;
  }

  reference_t operator*() const 
  {
    return *ptr_;
  }


private:
  T* ptr_;
  shared_count* pn_;
};

class A 
{
public:
  A(int v):value_(v)
  {}
  void test()
  {
    std::cout << "This is test " << value_ << std::endl;
  }
private:
  int value_;
};


int main()
{
  shared_ptr<A> p(new A(10));
  shared_ptr<A> p1 = p;
  std::cout << p1.use_count() << std::endl;
  p1->test();
  p->test();
  (*p).test();
  return 0;
}
