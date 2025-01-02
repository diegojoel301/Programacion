def mostrar(prueba, dato):
	if dato == True:
		print(f'Guess #{prueba} was correct.')
	else:
		print(f'Guess #{prueba} was incorrect.')

n, m = map(int, input().split())

partidos = {}

for i in range(n):
	x, y = input().split()
	partidos[x] = float(y)

for i in range(1, m + 1):
	cadena = input().replace('+', '').split()
	total = float(cadena[-1])
	s = 0
	for j in cadena:
		if j == '=':
			mostrar(i, s == total)
			break
		elif j == '>':
			mostrar(i, s > total)
			break
		elif j == '>=':
			mostrar(i, s >= total)
			break
		elif j == '<':
			mostrar(i, s < total)
			break
		elif j == '<=':
			mostrar(i, s <= total)
			break
		s += partidos[j]