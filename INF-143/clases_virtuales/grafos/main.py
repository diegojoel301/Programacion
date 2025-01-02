nodos, arcos = map(int, input().split())

nodos += 1

x = [0]*nodos

for i in range(nodos):
	x[i] = [0]*nodos

for i in range(arcos):
	origen, destino = map(int, input().split())
	x[origen][destino] = 1
	x[destino][origen] = 1

s = 0

for i in range(nodos):
	if x[2][i] != 0:
		s += 1
print(s)

# Lista de adyacencia

nodos, arcos = map(int, input().split())

nodos += 1

x = list()

for i in range(nodos):
	x.append([])

for i in range(arcos):
	origen, destino = map(int, input().split())
	x[origen].append(destino)
	x[destino].append(origen)

for i in x:
	print(i, x[i])


nodos, arcos = map(int, input().split())

nodos += 1

x = {}

for i in range(nodos):
	x.append([])

for i in range(arcos):
	origen, destino = input().split()

	if origen in x:
		y = x[origen]
		y.append(destino)
	else:
		x[origen] = destino
	

for i in x:
	print(i, x[i])