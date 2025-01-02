import sys

def hallar_codigo(x):
	y = list(x)
	y.sort()
	return ''.join(y)

def imprimir(s):
	if len(s) > 2:
		print(s[1:])

anagramas = []
#with open("ES.dic", encoding = 'utf-8') as f:
for i in sys.stdin:	
	#for i in f:
	palabra = i.strip()
	anagramas.append((hallar_codigo(palabra), palabra))
		
anagramas.sort()
s = [anagramas[0][0]]
# obtener todos los que son iguales
for x in anagramas:
	if x[0] in s:
		s.append(x[1])
	else:
		imprimir(s)
		s = [x[0]]