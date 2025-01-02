def f(k):
	return 192 + (250 * (k - 1))

T = int(input())

for _ in range(T):
	n = int(input())
	print(f(n))