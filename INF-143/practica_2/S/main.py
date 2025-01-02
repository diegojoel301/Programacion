while True:
	try:
		t = int(input())
		s = set()

		for _ in range(t):
			v = list(input().split())
			
			for i in range(1, len(v)):
				s.add(v[i])

		cad = input()

		aux = list()

		for i in s:
			aux.append(i)

		aux.sort()

		c = 0

		for i in aux:
			if i == cad:
				break
			else:
				c += 1
		print(c)
	except EOFError:
		break