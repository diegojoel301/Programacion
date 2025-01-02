import sys

solucion = list()

def sol():
	cad = input()

	abc = "abcdefghijklmnopqrstuvwxyz"

	ccl = 0 # contador de caracteres letra
	ccd = 0 # contador de caracteres desconocidos

	for i in cad:
		if i in abc:
			ccl += 1
		else:
			ccd += 1

	if ccl > ccd and cad[0] in abc:
		solucion.append(cad)

sys.stdin = open("input.txt", "r")

while True:
	try:
		sol()
	except EOFError:
		break
solucion.sort()
print(len(solucion))
print("***")
for i in solucion:
	print(i)