#include <queue> 
#include <iostream> 
using namespace std;

template <class T>
class stack{
  public:
    void push(T t)
    {
      //always push to q1
      q1.push(t);
    }
    T pop()
    {
      //same implementation as python. just moved some stuff into a function
      bool debug = false;
      if(debug){cout<<"in pop<<endl";}
      //if both queues empty, return None
      if(q1.empty() && q2.empty()){
         if(debug){cout<<"both queues empty"<<endl;}
         return '\0';
      }
      if(debug){cout<<"neither queue is empty"<<endl;}
      //if queue 1 is not empty, pop from this queue no matter what
      if(!q1.empty()){
         if(debug){cout<<"queue 1"<<endl;}
         //while queue 1 is not empty
         return popQueue(q1, q2, debug);
      }
      else{
         //same code as above, but pop from queue 2 instead of queue 1
         if(debug){cout<<"queue 2"<<endl;}
         return popQueue(q2, q1, debug);
      }
    };
    size_t size()
    {
      //size is size of q1 + size of q2
      int s = q1.size() + q2.size();
      return s;
    };
    bool isEmpty()
    {
      // is empty iff q1 and q2 are both empty
      bool e = q1.empty() && q2.empty();
      //cout<<"isEmpty: "<<e<<endl;
      return e;
    };
  private: 
    std::queue<T> q1;
    std::queue<T> q2;

    T popQueue(queue<T> &qpop, queue<T> &qpush, bool debug){
       while(!qpop.empty()){
            T val = qpop.front();
            qpop.pop();
            if(debug){
               if(val == '\0')
                  cout<<"POPPINg NULL"<<endl;
               else
                  cout<<"POPPING "<<val<<endl;
            }
            if(qpop.empty()){
               if(debug){cout<<"returning: "<<val<<endl;}
               return val;
            }
            qpush.push(val);
         }
    }
};

//==========================TESTING FUNCTIONS==============================
bool testPop(stack<int>& st, int expected, bool debug){
   //returns true if returned value of pop matches expected
   //prints debugging lines if debug
   int val = st.pop();
   if(val == expected){
      if(debug){
         if(expected == '\0')
            cout<<"PASSED pop.     a:e None:None"<<endl;
         else
           cout<<"PASSED pop.     e:a "<<expected<<":"<<val<<endl;
      }
      return true;
   }
   else{
      if(debug){
         if(val == '\0')//expected won't be null here
            cout<<"FAILED pop.     e:a "<<expected<<":null"<<endl;
         else
            cout<<"FAILED pop.     e:a "<<expected<<":"<<val<<endl;
      }
      return false;
   }
}

bool testSize(stack<int>& st, int expected, bool debug){
   //returns true if returned value of size matches expected
  //prints debugging lines if debug
   int si = st.size();
   if(si == expected){
      if(debug)
         cout<<"PASSED size.    e:a "<<expected<<":"<<si<<endl;
      return true;
   }
   else{
      if(debug)
         cout<<"FAILED size.    e:a "<<expected<<":"<<si<<endl;
      return false;
   }
}

bool testEmpty(stack<int>& st, int expected, bool debug){
   //returns true if returned value of isEmpty matches expected
   //prints debugging lines if debug
   bool mt = st.isEmpty();
   if(mt == expected){
      if(debug){
         if(expected)
            cout<<"PASSED isEmpty. e:a True:True"<<endl;
         else
            cout<<"PASSED isEmpty. e:a False:False"<<endl;
      }
      return true;
   }
   else{
      if(debug){
         if(mt)
            cout<<"FAILED isEmpty. e:a False:True"<<endl;
         else
            cout<<"FAILED isEmpty. e:a True:False"<<endl;
      }
      return false;
   }
}

//=================================TESTING=====================================
void testStack(){
   /*tests stack by calling:
    *   pop, size, and isEmpty on an empty stack
    *   pushing to a stack
    *   calling pop, size, and isEmpty from a non empty stack
    *   calling size and isEmpty on a stack with varying elements stored in queue 1 and queue 3
    */
   //cout<<"Testing Stack"<<endl;
   stack<int> s;
   int passed = 0;
   int count = 0;
   bool debugPop = false;
   bool debugSize = false;
   bool debugEmpty = false;
   //isEmpty on empty list
   count++;
   if(testEmpty(s, true, debugEmpty))passed++;
   //size on empty list
   count++;
   if(testSize(s, 0, debugSize))passed++;
   //pop on empty list
   count++;
   if(testPop(s, '\0', debugPop))passed++;
   //push 1
   s.push(1);
   //isEmpty on non empty list
   count++;
   if(testEmpty(s, false, debugEmpty))passed++;
   //size on stack of size 1
   count++;
   if(testSize(s, 1, debugSize))passed++;
   //push 2-6
   s.push(2);
   s.push(3);
   s.push(4);
   s.push(5);
   s.push(6);
   // isEmpty again
   count++;
   if(testEmpty(s, false, debugEmpty))passed++;
   //size on stack of size 6
   count++;
   if(testSize(s, 6, debugSize))passed++;
   //pop 6
   count++;
   if(testPop(s, 6, debugPop))passed++;
   //pop 5
   count++;
   if(testPop(s, 5, debugPop))passed++;
   //size on stack of size 5
   count++;
   if(testSize(s, 4, debugSize))passed++;
   // isEmpty again
   count++;
   if(testEmpty(s, false, debugEmpty))passed++;
   //pop 4
   count++;
   if(testPop(s, 4, debugPop))passed++;
   //size on stack of size 4
   count++;
   if(testSize(s, 3, debugSize))passed++;
   // isEmpty again
   count++;
   if(testEmpty(s, false, debugEmpty))passed++;
   //push 7
   s.push(7);
   //pop 7
   count++;
   if(testPop(s, 7, debugPop)) passed++;
   //push 8-10
   s.push(8);
   s.push(9);
   s.push(10);
   //pop 10
   count++;
   if(testPop(s, 10, debugPop))passed++;
   //pop 9
   count++;
   if(testPop(s, 9, debugPop))passed++;
   //pop 8
   count++;
   if(testPop(s, 8, debugPop))passed++;
   //pop 3-1
   int val = 3;
   while(val > 0 &&  !s.isEmpty()){
      count++;
      if(testPop(s, val, debugPop))passed++;
      val = val - 1;
   }

   //cout<<"=========================="<<endl;
   cout<<"passed "<<passed<<"/"<<count<<" tests"<<endl;
}

int main()
{
  //cout<<"in main"<<endl;
  stack<int> t1;
  if(! t1.isEmpty()) {std::cout << "FAILED isEmpty test stack should be empty" << std::endl; return -1;}
  //TODO test size function.
  t1.push(1);
  t1.push(2);
  t1.push(3);
  t1.push(4);
  t1.push(5);
  t1.push(6);
  if(t1.isEmpty()) {std::cout << "FAILED isEmpty test stack should be full" << std::endl; return -1;}
  //Cheap way to test.
  if(t1.pop() != 6) {std::cout << "FAILED at 6" << std::endl; return -1;}
  if(t1.pop() != 5) {std::cout << "FAILED at 5" << std::endl; return -1;}
  if(t1.pop() != 4) {std::cout << "FAILED at 4" << std::endl; return -1;}
  if(t1.pop() != 3) {std::cout << "FAILED at 3" << std::endl; return -1;}
  if(t1.pop() != 2) {std::cout << "FAILED at 2" << std::endl; return -1;}
  if(t1.pop() != 1) {std::cout << "FAILED at 1" << std::endl; return -1;}
  cout<<"passed given tests"<<endl;
  testStack();
  return 0;

}
