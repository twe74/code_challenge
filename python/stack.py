import queue
class stack:

   q1 = queue.Queue()
   q2 = queue.Queue()

   def push(self,item):
       print("PUSH ITEM")
   def pop(self):
       return -1;
   def size(self):
       return -1;
   def isEmpty(self):
       return False;

s = stack()
s.push(1)
s.push(2)
s.push(3)
s.push(4)
s.push(5)
s.push(6)
s.isEmpty()
s.pop()
#Write your own test to prove it works.
