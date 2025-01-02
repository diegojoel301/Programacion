def sd(n):
	s = 0
	for i in n:
		s += int(i)
	return str(s)

def a201(n):
	if len(n) > 1:
		return a201(sd(n))
	else:
		return n

t = int(input())

for _ in range(t):
	x, k = map(int, input().split())
	print(a201(str(x ** k)))