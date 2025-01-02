import math as m

def verifica(n):
	
	p = 0

	if n > 1:
		for i in range(2, int(m.sqrt(n)) + 1):
			if n % i == 0:
				p = 1
				break
		if p == 0:
			return True
		else:
			return False
	return False


v = [0 for i in range(1001)]

v[0] = 0
v[1] = 1
v[2] = 1

for i in range(2, 1001):
	v[i] = v[i - 1] + v[i - 2]

while True:
	try:
		n = int(input())

		if n <= 50:
			if verifica(v[n]):
				print("Es primo")
			else:
				print("No es primo")
		else:
			if verifica(n):
				print("Probablemente sea primo")
			else:
				print("No es primo")
	except EOFError:
		break