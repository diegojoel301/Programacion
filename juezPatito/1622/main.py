def sol(a, b, N, cad):
	cad += str(a) + "+" + str(b) + "+"
	v = list()
	v.append(a)
	v.append(b)

	for i in range(2, N):
		v.append(v[i - 1] + v[i - 2])
		cad += str(v[i]) + "+"

	return cad[0:len(cad) - 1]

t = int(input())

for _ in range(t):
	N = int(input())
	a, b = map(int, input().split())
	print(sol(a, b, N, ""))