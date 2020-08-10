#include <pthread.h>
#include <boost/noncopyable.hpp>    // noncopyable
#include <boost/checked_delete.hpp> // check_delete
#include <cstdio>
#include <cstdlib>
#include <string>
#include <stdexcept>

template<typename T>
class ThreadLocal : public boost::noncopyable
{
  public:
    typedef ThreadLocal<T>* pThreadLocal;
    ThreadLocal()
    { pthread_key_create( &pkey_, &ThreadLocal::destroy ); }

    ~ThreadLocal()
    { pthread_key_delete( pkey_ ); }

    T& value()
    {
      T* pvalue = reinterpret_cast<T*>( pthread_getspecific( pkey_ ) );
      if( !pvalue )
      {
        T* obj = new T();
        pthread_setspecific( pkey_, reinterpret_cast<void*>( obj ) );
        pvalue = obj;
      }
      return *pvalue;
    }

    T& operator*()
    {
      return value(); 
    }

    T* operator->() 
    {
      return &value();
    }

  private:
    static void destroy( void* arg )
    { 
      T* obj = reinterpret_cast<T*>( arg );
      boost::checked_delete( obj );
    }

    pthread_key_t pkey_;
};

class Logger
{
  public:
    Logger()
    {
      char fName[128] = "";
      sprintf(  fName, "log_%lu.log", static_cast<unsigned long>( pthread_self() ) );
      fp = fopen( fName, "w" );
      if( !fp ) throw std::runtime_error( std::string("can not create ") + fName );
    }

    ~Logger() { fclose( fp ); }

    void log( const std::string& s ) { fprintf( fp, "%s\n", s.c_str() ); }

  private:
    FILE* fp;
};

void* run( void* arg )
{
  auto ptllogger  = reinterpret_cast< ThreadLocal<Logger>::pThreadLocal>( arg);
  Logger& plogger = ptllogger->value();
  plogger.log( "Hello thread local" );
}

int main()
{
  ThreadLocal<Logger>::pThreadLocal p = new ThreadLocal<Logger>;
  (*(*p)).log( "Hello thread local" );
  (*p)->log( "Hello thread local" );

  pthread_t threads[2] = {0};
  pthread_create( &threads[0], NULL, run, reinterpret_cast<void*>( p ) );
  pthread_create( &threads[1], NULL, run, reinterpret_cast<void*>( p ) );
  pthread_join( threads[0], NULL );
  pthread_join( threads[1], NULL );
  delete p;
}
