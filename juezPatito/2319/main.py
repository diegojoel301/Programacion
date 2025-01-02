import math as m

def verifica(n):
	return m.ceil(m.sqrt(float(n))) == m.floor(m.sqrt(float(n)))

t = int(input())

while t > 0:
	n = int(input())

	x = 1

	for i in list(input().split()):
		x = x * int(i)

	if verifica(x):
		print("EL producto es numero cuadrado")
	else:
		print("El producto no es numero cuadrado")

	t -= 1