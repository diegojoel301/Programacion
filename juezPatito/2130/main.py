def verificaVocal(x):
	return x[0] == "a" or x[0] == "A" or x[0] == "e" or x[0] == "E" or x[0] == "i" or x[0] == "I" or x[0] == "o" or x[0] == "O" or x[0] == "u" or x[0] == "U"

def mostrar(cad):
	out = str()

	for e in cad:
		out += e + " "

	print(out[0:len(out) - 1])

cad = input().split()

cadv = list()
cadc = list()

for elem in cad:
	if verificaVocal(elem):
		cadv.append(elem)
	else:
		cadc.append(elem)

mostrar(cadv)
mostrar(cadc)
mostrar(cad)

print("Espacios en blanco:", len(cad) - 1)