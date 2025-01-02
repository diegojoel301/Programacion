import math as m

T = int(input())

for i in range(T):
	a, b = map(int, input().split())

	A = (a ** a) * m.log(a) + m.log(m.log(a))
	B = m.log(b ** b) + m.log(m.log(b))

	print(A > B)