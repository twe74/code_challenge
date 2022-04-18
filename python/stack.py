# Author: Paul Hennessee.
# Altered from base code at: https://github.com/twe74/code_challenge
# Date: 4/18/2022

try:
   import queue
except ImportError:
   import Queue as queue
class stack:

   q1 = queue.Queue()
   q2 = queue.Queue()

   def push(self,item):
      #always push to queue 1
      #print("PUSH "+str(item))
      self.q1.put(item)
   def pop(self):
      debug = False
      if(debug):print("in pop")
      #if both queues empty, return None
      if(self.q1.empty() and self.q2.empty()):
         if(debug):print("both queues empty")
         return None
      if(debug):print("neither queue is empty")
      #if queue 1 is not empty, pop from this queue no matter what
      if(not self.q1.empty()):
         if(debug):print("queue 1")
         #while queue 1 is not empty
         while(not self.q1.empty()):
            #pop from queue 1
            val = self.q1.get()
            if(debug):
               if(val == None):
                  print("POPPINg NONE")
               else:
                  print("POPPING "+str(val))
            #if queue 1 is empty, we want to stop popping and return this value
            if(self.q1.empty()):
               if(debug):print("returning: "+str(val))
               return val
            #otherwise push the value to queue 2 and keep popping
            self.q2.put(val)
      else:
         #same code as above, but pop from queue 2 instead of queue 1
         if(debug):print("queue 2")
         while(not self.q2.empty()):
            val = self.q2.get()
            if(debug):
               if(val == None):
                  print("POPPING NONE")
               else:
                  print("POPPING "+str(val))
            if(self.q2.empty()):
               if(debug):print("returning: "+str(val))
               return val
            self.q1.put(val)
   def size(self):
      #size of stack is combined size of queue 1 and 2
      #print(self.q1.size() + self.q2.size())
      return self.q1.qsize()+self.q2.qsize()
   def isEmpty(self):
      #stakc is empty only if both queues are empty
      #print self.q1.empty() and self.q2.empty()
      return self.q1.empty() and self.q2.empty()

#==========================TESTING FUNCTIONS==============================
def testPop(st, expected, debug):
   #returns true if returned value of pop matches expected
   #prints debugging lines if debug
   val = st.pop()
   if(val == expected):
      if(debug):
         if(expected == None):
            print("PASSED pop.     a:e None:None")
         else:
            print("PASSED pop.     e:a "+str(expected)+":"+str(val))
      return True
   else:
      if(debug):
         if(val == None):#expected won't be null here
            print("FAILED pop.     e:a "+str(expected)+":None")
         else:
            print("FAILED pop.     e:a "+str(expected)+":"+str(val))
      return False

def testSize(st, expected, debug):
   #returns true if returned value of size matches expected
   #prints debugging lines if debug
   si = st.size()
   if(si == expected):
      if(debug):
         print("PASSED size.    e:a "+str(expected)+":"+str(si))
      return True
   else:
      if(debug):
         print("FAILED size.    e:a "+str(expected)+":"+str(si))
      return False

def testEmpty(st, expected, debug):
   #returns true if returned value of isEmpty matches expected
   #prints debugging lines if debug
   mt = st.isEmpty()
   if(mt == expected):
      if(debug):
         if(expected):
            print("PASSED isEmpty. e:a True:True")
         else:
            print("PASSED isEmpty. e:a False:False")
      return True
   else:
      if(debug):
         if(mt):
            print("FAILED isEmpty. e:a False:True")
         else:
            print("FAILED isEmpty. e:a True:False")
      return False

#=================================TESTING=====================================
def testStack():
   #tests stack by calling:
   #    pop, size, and isEmpty on an empty stack
   #    pushing to a stack
   #    calling pop, size, and isEmpty from a non empty stack
   #    calling size and isEmpty on a stack with varying elements stored in queue 1 and queue 3

   #print("Testing Stack")
   s = stack()
   passed = 0
   count = 0
   debugPop = False
   debugSize = False
   debugEmpty = False
   #isEmpty on empty list
   count = count + 1
   if(testEmpty(s, True, debugEmpty)):
      passed = passed + 1
   #size on empty list
   count = count + 1
   if(testSize(s, 0, debugSize)):
      passed = passed + 1
   #pop on empty list
   count = count + 1
   if(testPop(s, None, debugPop)):
      passed = passed + 1
   #push 1
   s.push(1)
   #isEmpty on non empty list
   count = count + 1
   if(testEmpty(s, False, debugEmpty)):
      passed = passed + 1
   #size on stack of size 1
   count = count + 1
   if(testSize(s, 1, debugSize)):
      passed = passed + 1
   #push 2-6
   s.push(2)
   s.push(3)
   s.push(4)
   s.push(5)
   s.push(6)
   # isEmpty again
   count = count + 1
   if(testEmpty(s, False, debugEmpty)):
      passed = passed + 1
   #size on stack of size 6
   count = count + 1
   if(testSize(s, 6, debugSize)):
      passed = passed + 1
   #pop 6
   count = count + 1
   if(testPop(s, 6, debugPop)):
      passed = passed + 1
   #pop 5
   count = count + 1
   if(testPop(s, 5, debugPop)):
      passed = passed + 1
   #size on stack of size 5
   count = count + 1
   if(testSize(s, 4, debugSize)):
      passed = passed + 1
   # isEmpty again
   count = count + 1
   if(testEmpty(s, False, debugEmpty)):
      passed = passed + 1
   #pop 4
   count = count + 1
   if(testPop(s, 4, debugPop)):
      passed = passed + 1
   #size on stack of size 4
   count = count + 1
   if(testSize(s, 3, debugSize)):
      passed = passed + 1
   # isEmpty again
   count = count + 1
   if(testEmpty(s, False, debugEmpty)):
      passed = passed + 1
   #push 7
   s.push(7)
   #pop 7
   count = count + 1
   if(testPop(s, 7, debugPop)):
      passed = passed + 1
   #push 8-10
   s.push(8)
   s.push(9)
   s.push(10)
   #pop 10
   count = count + 1
   if(testPop(s, 10, debugPop)):
      passed = passed + 1
   #pop 9
   count = count + 1
   if(testPop(s, 9, debugPop)):
      passed = passed + 1
   #pop 8
   count = count + 1
   if(testPop(s, 8, debugPop)):
      passed = passed + 1
   #pop 3-1
   val = 3
   while(val > 0 and not s.isEmpty()):
      count = count + 1
      if(testPop(s, val, debugPop)):
         passed = passed + 1
      val = val - 1

   #print("==========================")
   print("passed "+str(passed)+"/"+str(count)+" tests")

#Write your own test to prove it works.
testStack()
