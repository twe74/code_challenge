#include <queue> 
#include <iostream> 

template <class T>
class stack{
  public: 
    void push(T t)
    {
      //TODO implement push function
    }
    T pop()
    {
      //TODO implement pop fuiunction

      return -1;
    };
    size_t size()
    {
      //TODO implement size
      return -1;
    };
    bool isEmpty()
    {
      // TODO implement is empty 
      return false;
    };
  private: 
    std::queue<T> q1;
    std::queue<T> q2;
};

int main()
{
  stack<int> t1;
  if(! t1.isEmpty()) std::cout << "FAILED isEmpty test stack should be empty" << std::endl; return -1;
  //TODO test size function.
  t1.push(1);
  t1.push(2);
  t1.push(3);
  t1.push(4);
  t1.push(5);
  t1.push(6);
  if(t1.isEmpty()) std::cout << "FAILED isEmpty test stack should be full" << std::endl; return -1;
  //Cheap way to test.
  if(t1.pop() != 6) std::cout << "FAILED at 6" << std::endl; return -1;
  if(t1.pop() != 5) std::cout << "FAILED at 5" << std::endl; return -1;
  if(t1.pop() != 4) std::cout << "FAILED at 4" << std::endl; return -1;
  if(t1.pop() != 3) std::cout << "FAILED at 3" << std::endl; return -1;
  if(t1.pop() != 2) std::cout << "FAILED at 2" << std::endl; return -1;
  if(t1.pop() != 1) std::cout << "FAILED at 1" << std::endl; return -1;
  return 0;

}
