import math as m
def f(n):
	return n * (n + 1) / 2

x = 1000000000000
r1 = (-1 + m.sqrt(1 + (8 * (x - 1)))) / 2
r2 = int((-1 + m.sqrt(1 + (8 * (x - 1)))) / 2)

if r1 != r2:
	low = 1
	high = 2 * 1000000000000

	while(high - low > 1):
		mid = (high + low) // 2;
		if f(mid) + 1 <= x:
			low = mid;
		else:
			high = mid;
	print(x - f(low))
else:
	print("1")
