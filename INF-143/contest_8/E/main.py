salidas = list()

def sol():
	cipher = input()

	mapa = dict()

	x = 97

	for i in cipher:
		mapa[i] = chr(x)
		x += 1
	mapa[' '] = ' '
	n = int(input())
	salida = str()

	for _ in range(n):
		line = input()
		for i in line:
			salida += mapa[i]
		salida += "\n"

	salidas.append(salida)
while True:
	try:
		sol()
	except EOFError:
		break
"""
salida = str()
for i in range(len(salidas) - 1):
	salida += salidas[i]
salida += salidas[len(salidas) - 1][0:len(salidas[len(salidas) - 1]) - 1]
print(salida)
"""