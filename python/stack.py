#used the same implementation here as I used in stack.cpp
import queue
class stack:

   q1 = queue.Queue()
   q2 = queue.Queue()
   qTemp = queue.Queue()

   def push(self,item):
       self.q2.put(item)

       while not self.q1.empty():
              popper = self.q1.get()
              self.q2.put(popper)   
            
       self.qTemp = self.q1
       self.q1 = self.q2
       self.q2 = self.qTemp

       for i in self.q1.queue:
          print(i, end=" ")

       print(" --> Stack after push")

   def pop(self):
       
       if self.q1.empty():
         return
       else:
          popper2 = self.q1.get()
          
       for i in self.q1.queue:
          print(i, end=" ")
       print(" --> Stack after pop")
       return popper2          

   def size(self):
       return self.q1.qsize() + self.q2.qsize()

   def isEmpty(self):
       if(self.q1.empty() and self.q2.empty()):
         return True
       else:
         return False
       

s = stack()
print("\nPYTHON VERSION\n")

s.push(1)
if s.size()!=1: print("Size not equal to 1, returned size is: " + str(s.size()))
s.push(2)
if s.size()!=2: print("Size not equal to 2, returned size is: " +str(s.size()))
s.push(3)
if s.size()!=3: print("Size not equal to 3, returned size is: " + str(s.size()))
s.push(4)
if s.size()!=4: print("Size not equal to 4, returned size is: " + str(s.size()))
s.push(5)
if s.size()!=5: print("Size not equal to 5, returned size is: " + str(s.size()))
s.push(6)
if s.size()!=6: print("Size not equal to 6, returned size is: " + str(s.size()))

if(s.isEmpty() ==True): 
  print("Error - stack has content yet isEmpty returned true") 
  quit()
  
print("") #separates pushes and pops

if(s.pop()!= 6):
  print("First pop should return 6")
  quit()
if s.size()!=5: 
  print("Size not equal to 5, returned size is: " + str(s.size()))
  quit()

if(s.pop()!= 5):
  print("Second pop should return 5")
  quit()
if s.size()!=4: 
  print("Size not equal to 4, returned size is: " + str(s.size()))
  quit()

if(s.pop()!= 4):
  print("Third pop should return 4")
  quit()
if s.size()!=3: 
  print("Size not equal to 43, returned size is: " + str(s.size()))
  quit()

if(s.pop()!= 3):
  print("Fourth pop should return 3")
  quit()
if s.size()!=2: 
  print("Size not equal to 2, returned size is: " + str(s.size()))
  quit()

if(s.pop()!= 2):
  print("Fifth pop should return 2")
  quit()
if s.size()!=1: 
  print("Size not equal to 1, returned size is: " + str(s.size())) 
  quit()

if(s.pop()!= 1):
  print("Sixth pop should return 1")
  quit()
if s.size()!=0: 
  print("Size not equal to 0, returned size is: " + str(s.size()))
  quit()

if(s.pop()!= None):
  print("Seventh pop should return None")
  quit()
if s.size()!=0: 
  print("Size not equal to 0, returned size is: " + str(s.size()))
  quit()
print("\nCode passed all tests successfully")
