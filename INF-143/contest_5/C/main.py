import math as m
def suma(v, x):
	s = 0
	for e in v:
		s += x // e

	return s
v =  [80, 3, 19, 62, 77, 71, 86, 17, 40, 96, 20, 55, 95, 2, 29, 20, 34, 13, 61, 27, 80, 23, 83, 40, 72, 37, 46, 99, 77, 43]
k = 3922
low = 0
high = 1000000

while high - low > 1:
	mid = (high + low) // 2
	if suma(v, mid) < k:
		low = mid
	else:
		high = mid

print(high)