def cantidad(v):
	c = 0
	for i in range(1, len(v)):
		if v[i - 1] == v[i]:
			c += 1
			if i != len(v) - 1:
				if v[i - 1] == v[i + 1]:
					if v[i - 1] == 'G':
						v[i] = 'R'
					elif v[i - 1] == 'Y':
						v[i] = 'G'
					elif v[i - 1] == 'R':
						v[i] = 'B'
					elif v[i - 1] == 'B':
						v[i] = 'Y'
				else:
					if (v[i - 1] == 'G' and v[i + 1] == 'R') or (v[i - 1] == 'R' and v[i + 1] == 'G'):
						v[i] = 'B'
					elif (v[i - 1] == 'G' and v[i + 1] == 'B') or (v[i - 1] == 'B' and v[i + 1] == 'G'):
						v[i] = 'R'
					elif (v[i - 1] == 'G' and v[i + 1] == 'Y') or (v[i - 1] == 'Y' and v[i + 1] == 'G'):
						v[i] = 'R'
					elif (v[i - 1] == 'R' and v[i + 1] == 'Y') or (v[i - 1] == 'Y' and v[i + 1] == 'R'):
						v[i] = 'B'
					elif (v[i - 1] == 'R' and v[i + 1] == 'B') or (v[i - 1] == 'B' and v[i + 1] == 'R'):
						v[i] = 'G'
					elif (v[i - 1] == 'B' and v[i + 1] == 'Y') or (v[i - 1] == 'Y' and v[i + 1] == 'B'):
						v[i] = 'G'
			else:
				if v[i - 1] == 'B':
					v[i] = 'R'
				elif v[i - 1] == 'Y':
					v[i] = 'G'
				elif v[i - 1] == 'R':
					v[i] = 'B'
				elif v[i - 1] == 'B':
					v[i] = 'Y'
	return c

L = int(input())
cad = str()
for _ in range(L):
	cad = list(input())
	print(cantidad(cad))