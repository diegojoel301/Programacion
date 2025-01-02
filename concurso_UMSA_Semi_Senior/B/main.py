from queue import PriorityQueue

def sol():
	cad = list(input().split(' '))
	pq = PriorityQueue()

	for i in cad:
		if i != ' ' and i != '':
			pq.put(int(i))
	c = 0
	t1 = 0
	t2 = 0

	while not pq.empty():
		val = pq.get()
		if c % 2 == 0:
			t1 += val
		else:
			t2 += val
		c += 1

	print(abs(t1 - t2))

while True:
	try:
		sol()
	except EOFError:
		break