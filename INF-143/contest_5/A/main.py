def izquierda(n):
	return (n - 1) * (n) / 2;

def derecha(n, N):
	return (N * (N + 1) / 2) - (n * (n + 1) / 2)

def f(n, N):
	return izquierda(n) == derecha(n, N)

def sol():
	n = int(input())
	low = 1; high = n;
		
	while high - low > 1 :

		mid = (low + high) // 2;
		
		if izquierda(mid) <= derecha(mid, n):
			low = mid
		else:
			high = mid
	if f(low, n):
		print(low)
	else:
		print("NO")

while True:
	try:
		sol()
	except EOFError:
		break