def f(n):
	if n == 1:
		return 0
	else:
		return min(f(n - 1), (n % 2) + f(n // 2), (n % 3) + f(n // 3))

f(3)
