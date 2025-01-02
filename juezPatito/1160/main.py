"""
	v d e
	3 2 1
	2 1 2
	3 0 4

"""

for _ in range(int(input())):
	tabla = []
	for _ in range(int(input())):
		v, d, e = map(int, input().split())
		tabla.append((v, -d, e))
	tabla.sort()
	print(tabla[len(tabla) - 1][0], -tabla[len(tabla) - 1][1], tabla[len(tabla) - 1][2])