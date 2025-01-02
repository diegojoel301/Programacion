def criba():
	primos = [True] * maximo

	primos[0] = primos[1] = False

	for i in range(maximo):
		if primos[i]:
			if i > 999:
				lista_primos.append(i)

			for j in range(i + i, maximo, i):
				primos[j] = False

def distancia_uno(a, b):
	d = 0
	for i in range(4):
		if a % 10 != b % 10:
			d += 1
		a //= 10
		b //= 10
	return d == 1

def crear_grafo():
	for desde in range(nodos):
		for hasta in range(desde + 1, nodos):
			if distancia_uno(lista_primos[desde], lista_primos[hasta]):
				grafo[lista_primos[desde]].append(lista_primos[hasta])
				grafo[lista_primos[hasta]].append(lista_primos[desde])

def bfs(src, dest):
	q = list()
	dist = [-1] * (maximo + 1)
	dist[src] = 0

	q.append(src)

	while len(q) > 0:
		desde = q.pop(0)
		if desde == dest:
			return dist[dest]
		for hasta in grafo[desde]:
			if dist[hasta] == -1:
				dist[hasta] = dist[desde] + 1
				q.append(hasta)
	return 9999999

maximo = 9999
lista_primos = list()
grafo = [[] for _ in range(maximo)]
criba()
nodos = len(lista_primos)
crear_grafo()

for _ in range(int(input())):
	a, b = map(int, input().split())
	print(bfs(a, b))
