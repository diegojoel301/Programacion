def verifica_elimina(cad, k):
	for i in range(len(cad) - k + 1):
		char = cad[i]
		scad = cad[i:i + k]

		if scad == (char * k):
			izq = cad[0:i]
			der = cad[i + k: len(cad)]
			cad = izq + der

			return True, cad

	return False, cad

n, k = map(int, input().split())
cad = input()

out = verifica_elimina(cad, k)
cad = out[1]

while out[0]:
	out = verifica_elimina(cad, k)
	cad = out[1]

print(out[1])