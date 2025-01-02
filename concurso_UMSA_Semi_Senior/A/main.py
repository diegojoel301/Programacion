import math as m

def f(x):
	return (-1 + m.sqrt((8 * x) + 1)) / 2

def g(x):
	return x * (x + 1) // 2

T = int(input())

for _ in range(T):
	N = int(input())

	a = f(N)

	if a == int(a):
		print("Go On Bob", int(a))
	else:
		print("Better Luck Next Time")
