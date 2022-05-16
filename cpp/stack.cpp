#include <queue> 
#include <iostream> 

template <class T>
class stack{
   int sizeVar;
  public: 
  	stack()
	{
		sizeVar = 0; //initialize size of stack
	}

    void push(T t)
    {
      sizeVar++; // increment size of stack
      q2.push(t); //push new value to q2 each time push function is called

// while q1 has values, push the first value from q1 to q2, popping it from q1 after each push
// to q2.  This way the new value pushed will always be first in our new queue, then swap q1 and q2 to get ready for next iteration
      while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
      }
        // swap names of q1 and q2 to get ready for next call to push function -- q1 will always be our "Stack"
          std::queue<T> q = q1;
           q1 = q2;
           q2 = q;

     std::queue<int> q_copy = q1;
    while (!q_copy.empty())
    {
        int front = q_copy.front();
        std::cout << front << " ";
        q_copy.pop();
    }
     std::cout << " --> Stack after a push" << std::endl;
    }

    T pop(){
      		if (q1.empty()){
		      	return -1;
          }
          else{
            sizeVar--;
            int popper = q1.front();
            q1.pop();
               std::cout << "Stack after a pop --> ";
            std::queue<int> qAnother = q1;
            while (!qAnother.empty())
            {
                int front = qAnother.front();
                std::cout << front << " ";
                qAnother.pop();
            }
            std::cout << std::endl;
            return popper;
          }
    };

    size_t size(){
      return sizeVar;
    };

    bool isEmpty(){
      if(q1.empty() && q2.empty()){
        // std::cout << "Yes, it is empty" << std::endl;
       return true;
      }
      else{
         // std::cout << "No, it is NOT empty" << std::endl;
      return false;
      }
    };

  private: 
    std::queue<T> q1;
    std::queue<T> q2;
};

int main()
{
  
  stack<int> t1;
  std::cout << "\n C++ VERSION\n" << std::endl;

  if(! t1.isEmpty()){ std::cout << "FAILED isEmpty test stack should be empty" << std::endl; return -1;}
  
  t1.push(1);
    if(t1.size() != 1){ std::cout << "size should be 1, size returned is " << t1.size() << std::endl; return -1;}
  t1.push(2);
    if(t1.size() != 2){ std::cout << "size should be 2, size returned is " << t1.size() << std::endl; return -1;}
  t1.push(3);
      if(t1.size() != 3){ std::cout << "size should be 3, size returned is " << t1.size() << std::endl; return -1;}
  t1.push(4);
      if(t1.size() != 4){ std::cout << "size should be 4, size returned is " << t1.size() << std::endl; return -1;}
  t1.push(5);
      if(t1.size() != 5){ std::cout << "size should be 5, size returned is " << t1.size() << std::endl; return -1;}
  t1.push(6);
      if(t1.size() != 6){ std::cout << "size should be 6, size returned is " << t1.size() << std::endl; return -1;}

std::cout << " " << std::endl; //space between push and pop

  if(t1.isEmpty()){ std::cout << "FAILED isEmpty test stack should be full" << std::endl; return -1;}
  //Cheap way to test.
  if(t1.pop() != 6){ std::cout << "FAILED at 6" << std::endl; return -1;}
        if(t1.size() != 5){ std::cout << "size should be 5, size returned is " << t1.size() << std::endl; return -1;}

  if(t1.pop() != 5){ std::cout << "FAILED at 5" << std::endl; return -1;}
          if(t1.size() != 4){ std::cout << "size should be 4, size returned is " << t1.size() << std::endl; return -1;}

  if(t1.pop() != 4){std::cout << "FAILED at 4" << std::endl; return -1;}
          if(t1.size() != 3){ std::cout << "size should be 3, size returned is " << t1.size() << std::endl; return -1;}

  if(t1.pop() != 3){std::cout << "FAILED at 3" << std::endl; return -1;}
          if(t1.size() != 2){ std::cout << "size should be 2, size returned is " << t1.size() << std::endl; return -1;}

  if(t1.pop() != 2){std::cout << "FAILED at 2" << std::endl; return -1;}
          if(t1.size() != 1){ std::cout << "size should be 1, size returned is " << t1.size() << std::endl; return -1;}

  if(t1.pop() != 1){std::cout << "FAILED at 1" << std::endl; return -1;}
          if(t1.size() != 0){ std::cout << "size should be 0, size returned is " << t1.size() << std::endl; return -1;}

std::cout << "\nAll tests succeeded." << std::endl;
  return 0;
}
