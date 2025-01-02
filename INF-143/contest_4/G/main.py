import sys

def sumDigitos(n):
	s = 0
	for e in n:
		if e.isnumeric():
			s += int(e)
	return s

def compareStrings(a, b):
	for i in range(len(a)):
		if ord(a[i]) > ord(b[i]):
			return 0
		elif ord(b[i]) > ord(a[i]):
			return -1				
	return -1


def compareTo(a, b):
	if len(a) > len(b):
		return 0
	elif len(a) == len(b):
		if sumDigitos(a) > sumDigitos(b):
			return 0
		elif sumDigitos(a) == sumDigitos(b):
			if compareStrings(a, b) == 0:
				return 0
	return -1

def mostrar(v):
	for e in v:
		print(e, end = " ")
	print()

def sol():
	cad = list(input().split())

	for i in range(0, len(cad)):
		for j in range(0, len(cad) - 1):
			if compareTo(cad[j], cad[j + 1]) == 0:
				aux = cad[j + 1]
				cad[j + 1] = cad[j]
				cad[j] = aux
	mostrar(cad)

sys.stdin = open("input.txt", "r")

while True:
	try:
		sol()
	except EOFError:
		break