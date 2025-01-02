def convertir(n):
	cad = "{0:b}".format(int(n))
	binary = (8 - len(cad)) * "0" + cad
	return binary[4:8] + binary[0:4]

while True:
	try:
		v = list(input())
		for i in range(len(v) - 1):
			print(int(convertir(ord(v[i])), 2), end = " ")
		print(int(convertir(ord(v[len(v) - 1])), 2))
	except EOFError:
		break


