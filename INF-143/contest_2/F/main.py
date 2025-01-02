import math as m

def cantidadDigitos(n):
	return int(m.log10(n)) + 1

def ldx(x):
	v = [2, 4, 8, 6]
	return v[x % 4 - 1]
def ldy(y):
	v = [3, 9, 7, 1]
	return v[y % 4 - 1]

def sol(x, y):
	if(cantidadDigitos(x) <= 1 or (cantidadDigitos(x) > 1 and cantidadDigitos(y) > 1)):
		return (ldx(x) + ldy(y)) % 10
	if(cantidadDigitos(y) <= 1):
		return (ldx(x) - 1) % 10

while True:
	try:
		x, y = map(int, input().split())
		print(sol(x, y))
	except EOFError:
		break