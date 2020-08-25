#include <iostream>

class shared_count {
public:
  shared_count():counter_(0) 
  {
  }

  shared_count(const shared_count& rh)
  {
    counter_ = rh.counter_;
  }

  int add_ref() 
  {
    return __sync_add_and_fetch(&counter_, 1);
  }

  int sub_ref() 
  {
    return __sync_sub_and_fetch(&counter_, 1);
  }

  int use_count()
  {
    return counter_;
  }

private:
  int counter_;
};

template<class T>
class shared_ptr
{
  typedef T* pointer_t;
  typedef T& reference_t;

public:
  shared_ptr():ptr_(),pn_()
  {
  }

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
    if (this == &rh) return *this;
    shared_ptr<T> dummy;
    dummy.swap(*this);
    ptr_ = rh.ptr_;
    pn_ =  rh.pn_;
    pn_->add_ref();
    return *this;
  }

  void reset(T* p) 
  {
    shared_ptr<T> dummy;
    dummy.swap(*this);
    ptr_ = p;
    pn_ = new shared_count(); 
    pn_->add_ref();
  }

  void swap(shared_ptr<T>& other)
  {
    std::swap(ptr_, other.ptr_);
    shared_count* temp_pn = pn_;
    pn_ = other.pn_;
    other.pn_ = temp_pn;
  }
  
  int use_count() const
  {
    return pn_ ? pn_->use_count() : 0;
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
  shared_ptr<A> p1(new A(11));
  p1 = p;
  std::cout << p1.use_count() << std::endl;
  return 0;
}
