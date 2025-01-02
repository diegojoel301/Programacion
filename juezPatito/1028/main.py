def cantidad(v):
	key = -1
	c = 0
	for j in range(1, len(v)):
		key = v[j]
		i = j - 1

		while i > - 1 and int(v[i]) > int(key):
			v[i + 1] = v[i]
			i -= 1
			c += 1
		v[i + 1] = key

	return c
while True:
	try:
		v = input().split()
		print(cantidad(v))
	except EOFError:
		break