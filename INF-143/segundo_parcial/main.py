v = list()
with open("texto.txt") as archivo:
	for linea in archivo:
		line = str(linea)

		cad = str()

		for i in line:
			if i != '.' and i != ',' and '\n' and i != ':':
				cad += i.upper()
		
		aux = list(cad.split())

		for i in aux:
			v.append(i)

mapa1 = {} # mapa1[palabra] = indice
mapa2 = {} # mapa2[indice] = palabra

index = 0

for i in v:
	if not i in mapa1.keys():
		mapa1[i] = index
		mapa2[index] = i
		index += 1

adj = list()

n = len(mapa2)

for _ in range(0, n):
	adj.append(set())

aux = str()

aux = v[0]

for i in range(1, len(v)):
	#print(aux, v[i])
	adj[mapa1[aux]].add(mapa1[v[i]])
	aux = v[i]

def dfs(node, vis, pila):

	vis[node] = True
	pila[node] = True
	print(mapa2[node], end = " ")
	for i in adj[node]:
		if not vis[i]:
			if dfs(i, vis, pila) == True:
				return True
		elif pila[i] == True:
			return True

	pila[node] = False
	return False

def bfs(node):

	vis = [False] * n

	padre = [-1] * n

	q = list()

	q.append(node)

	print(mapa2[node], end = " ")

	while len(q) != 0:
		u = q.pop(0)

		if u != node:
			print(mapa2[u], end = " ")
		for i in adj[u]:
			if not vis[i]:
				vis[i] = True
				q.append(i)
				padre[i] = u
			elif padre[u] != i:
				return True
	return False

prueba = input("[*] Introduce cadena: ").upper()


vis = [False] * n
pila = [False] * n

print("[+] DFS:")

dfs(mapa1[prueba], vis, pila)

print()

print("[+] BFS:")

bfs(mapa1[prueba])

print()
