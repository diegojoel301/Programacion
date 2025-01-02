def criba(prime, n):
	p = 2

	while p * p <= n:
		if prime[p] == True:
			for i in range(p * p, n + 1, p):
				prime[i] = False
		p += 1
	prime[0] = prime[1] = False

def factorial(v, n):
	v[1] = 1

	for i in range(2, n + 1):
		v[i] = i * v[i - 1]
		v[i] = (i % 10007) * (v[i - 1] % 10007)
	v[n] = v[n] % 10007

def doble_factorial(n):
	res = 1

	for i in range(n, -1, -2):
		if i == 0 or i == 1:
			return res % 10007
		else:
			res = (res % 10007) * (i % 10007) 

	return res % 10007

def primordial(n, prime):
	res = 1

	for i in range(1, n + 1):
		if prime[i]:
			res = (res % 10007) * (i % 10007)
	return res % 10007

def superFactorial(v, n):
	res = 1

	for i in range(1, n + 1):
		res = (res % 10007) * (v[i] % 10007)

	return res % 10007

def power(x, y, p):
	res = 1

	x = x % p

	if x == 0:
		return 0

	while y > 0:

		if (y & 1) == 1:
			res = (res * x) % p

		y = y >> 1
		x = (x * x) % p

	return res

def hiperfactorial(v, n):
	v[1] = 1

	for i in range(2, n + 1):
		v[i] = power(i, i, 10007) * (v[i - 1] % 10007)

prime = [True for i in range(1 + 10**5)]
factoRes = [0 for i in range(1 + 10**5)]
hiperfacto = [0 for i in range(1 + 10**5)]

criba(prime, 10**5)
factorial(factoRes, 10**5)
hiperfactorial(hiperfacto, 10**5)

t = int(input())

for _ in range(t):
	n = int(input())
	print(factoRes[n] % 10007, doble_factorial(n), primordial(n, prime), superFactorial(factoRes, n), hiperfacto[n] % 10007)

