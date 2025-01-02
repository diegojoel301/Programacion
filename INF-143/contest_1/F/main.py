def facto(n):

	v = list()

	v.append(1)

	for i in range(1, n + 1):
		v.append(v[i - 1] * i)

	return v[n]
def sol(f, c):
	return facto(f + c) // (facto(f) * facto(c))

f = -1
c = -1

while f != 0 and c != 0:
	f, c = map(int, input().split())
	if f == 0 and c == 0:
		break
	print(sol(f, c))