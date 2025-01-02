"""
def factorial(n):
	print(n, end = ' ')
	if n == 0:
		return 1
	return n * factorial(n - 1)
def cambio_base(n, base):

	global resp

	if n == 0:
		return resp

	d = n % base
	n //= base

	resp = str(d) + resp

	cambio_base(n, base)

def f(n, a = 1):
	if n == 0:
		return a
	return f(n - 1, n * a)

resp = ''
cambio_base(10, 2)
print(resp)

#factorial(5)
print(f(5))
"""
"""
''' Hallar la suma de n numero'''
import time, timeit

def con_while():
	global n
	s = 0

	i = 1

	while i <= n:
		s += i
		i += 1
	return s

def con_for():
	global n
	s = 0
	for i in range(1, n + 1):
		s = s + i
	return s

def medir_tiempo():
	global n
	inicio = time.time()
	con_while(n)
	fin = time.time()

	print('con while:', fin)

	inicio = time.time()
	con_for(n)
	fin = time.time()

	print('con while:', fin)	

n = 10_000_000

print('con while: ', timeit.timeit(con_while, number = 1))
print('con for: ', timeit.timeit(con_for, number = 1))
"""

import profile, cProfile

''' fibonacci
	queremos conocer el fibonacci n
'''
# memorization
# memorandum = recordatorio
recordatorio = [0] * 100

def f_iterativa(n):
	f = [0] * (n + 1) # creamos el vector
	f[0], f[1] = 0, 1

	for i in range(2, n + 1):
		f[i] = f[i - 2] + f[i - 1]

	return f[n]

def f_recursivo(n):
	if n < 2:
		return n
	return f_recursivo(n - 1) + f_recursivo(n - 2)

def f_recursivo_2(n):

	if n == 0:
		return 0
	if n == 1:
		recordatorio[n] = 1
		return 1

	if recordatorio[n] > 0:
		return recordatorio[n]

	recordatorio[n] = f_recursivo(n - 1) + f_recursivo(n - 2)

	return recordatorio[n]


def probar():
	n = 30
	print(f_iterativa(n))
	print(f_recursivo(n))
	print(f_recursivo(n))

#profile.run('probar()' )
cProfile.runctx('probar()', globals(), {'n' : 10}, 'output.prof')