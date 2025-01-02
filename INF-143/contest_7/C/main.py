from queue import PriorityQueue

x = [1, 2 ,3]

l = PriorityQueue()

for i in x:
	l.put(-i)

s = 0

while l.qsize() > 1:
	a = l.get() # O(1)
	b = l.get() # O(1)
	c = a + b
	l.put(c) # O(1)
	s += c
	print(a, b, c)

print(s)