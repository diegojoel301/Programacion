def f(n):
	if n == 0:
		return 1
	else:
		return n * f(n - 1)

def comb(n, k):
	return f(n) // (f(k) * f(n - k))

def SS(k, n):
	return comb(n + k, k + 1)

while True:
	try:
		k, n = map(int, input().split())
		print(SS(k, n))
	except EOFError:
		break