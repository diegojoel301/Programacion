adj = list()
n = 6
for _ in range(0, n):
	adj.append(list())
"""
adj[0].append(1)
adj[1].append(4)
adj[4].append(2)
adj[2].append(3)
adj[3].append(4)
adj[3].append(5)
"""
"""
adj[0].append(2)
adj[2].append(0)

adj[2].append(3)
adj[3].append(2)

adj[3].append(4)
adj[4].append(2)

adj[5].append(3)
adj[3].append(5)

adj[3].append(0)
adj[0].append(3)
"""

adj[0].append(1)
#adj[1].append(0)

adj[1].append(4)
#adj[4].append(1)

adj[4].append(2)
#adj[2].append(4)

adj[2].append(3)
#adj[3].append(2)

adj[3].append(4)
#adj[4].append(3)

adj[3].append(5)
#adj[5].append(3)

def dfs(node, vis, flag, parent_node):
	if flag:
		print(node)
		for i in adj[node]:
			if parent_node == i:
				flag = False
			if not vis[i]:
				vis[i] = True
				dfs(i, vis, flag, parent_node)
	else:
		print("Gabo")
		exit(0)

def dfs1(node, vis, pila):

	vis[node] = True
	pila[node] = True
	print(node)
	for i in adj[node]:
		if not vis[i]:
			if dfs1(i, vis, pila) == True:
				return True
		elif pila[i] == True:
			return True

	pila[node] = False
	return False

def bfs_contador_de_hijos(node):
	vis = [False] * n

	q = list()

	ans = 0

	q.append(node)
	vis[node] = True

	while len(q) != 0:
		u = q.pop(0)
		print(u)
		ans += 1
		for i in adj[u]:
			if not vis[i]:
				vis[i] = True
				q.append(i)
	return ans

def bfs(node):

	vis = [False] * n

	padre = [-1] * n

	q = list()

	q.append(node)

	print(node)

	while len(q) != 0:
		u = q.pop(0)

		if u != node:
			print(u)
		for i in adj[u]:
			if not vis[i]:
				vis[i] = True
				q.append(i)
				padre[i] = u
			elif padre[u] != i:
				return True
	return False

vis = [False] * n
pila = [False] * n

dfs1(0, vis, pila)