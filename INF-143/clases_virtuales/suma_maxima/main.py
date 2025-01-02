def trivial():
	suma_maxima = 0
	n = len(x)

	for i in range(n):
		s = 0
		for j in range(n):
			for k in range(i, j + 1):
				s += x[k]
			suma_maxima = max(suma_maxima, s)

	return suma_maxima

def cuadratica():
	suma_maxima = 0
	n = len(x)

	for i in range(n):
		for j in range(n):
			s = s + x[]
			for k in range(i, j + 1):
				s += x[k]
			suma_maxima = max(suma_maxima, s)

	return suma_maxima


def cuadratica():
	

n = len(x)

acumulado = [x[0]]

for i in range(n):
	acumulado.append(x[i] + acumulado[i - 1])

print(acumulado)