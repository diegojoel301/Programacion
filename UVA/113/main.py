import math as m
while True:
	try:
		n = int(input())
		p = int(input())

		print(int(round(m.pow(p, 1 / n), 0)))

	except EOFError:
		break