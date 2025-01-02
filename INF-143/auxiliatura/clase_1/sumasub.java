n = leer()

s = leer()

a = []

for i in range(0, n):
	a[i] = leer()

res = 0

for comb in range(0, 2 ** n):

	for i in range(0, n):
		if comb & (1 << i) > 0: //comb en la posicion i esta encendido
			sum += a[i]
	if sum == s:
		res++
print(res)

/*
	comb = 101010
		   001000
		   000001-> 1 << 3
*/