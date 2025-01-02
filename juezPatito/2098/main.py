def verificaVocal(x):
	return x == "a" or x == "e" or x == "i" or x == "o" or x == "u"

def genera(x):
	vocales = list()
	out = str()

	for elem in x:
		if verificaVocal(elem):
			vocales.append(elem)

	if not "a" in vocales:
		out += "a"
	if not "e" in vocales:
		out += "e"
	if not "i" in vocales:
		out += "i"
	if not "o" in vocales:
		out += "o"
	if not "u" in vocales:
		out += "u"

	return out

def mostrar(cad):
	out = str()

	for e in cad:
		out += e + " "

	print(out[0:len(out) - 1])

T = int(input())

for _ in range(T):
	cad = input().split()
	v = list()

	for elem in cad:
		v.append(genera(elem))

	mostrar(v)