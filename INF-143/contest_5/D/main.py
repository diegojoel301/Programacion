import math

def BS(n):
	low = 10
	high = 100000000

	while high - low > 1:
		mid = (high + low) // 2

		funcion = f(mid)

		if funcion[2] <= n:
			low = mid
			m = funcion[0]
			t = funcion[1]
		else:
			high = mid
	return m, t

def y(x, m, n):
	return m * x - n
def x(y, m, n):
	return math.ceil((y + m) / n)

def f(n):
	l = len(str(n))
	cota_inferior = 10 ** (l - 1)
	num = 9
	s = 9
	while len(str(num)) != l:
		num = int(str(num) + "9")
		s += num
	return l, s - num, y(cota_inferior, l, s - num)

def sol():
	n = int(input())
	if n <= 9 or n == 10:
		if n == 10:
			print(1)
		else:
			print(n)
	else:
		res = BS(n)
		value = x(n, res[1], res[0])
		value_2 = y(value, res[0], res[1])
		print(str(value)[len(str(value)) - 1 - (value_2 - n)])

while True:
	try:
		sol()
	except EOFError:
		break