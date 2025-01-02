def mostrar(v):
	out = str()
	for i in range(len(v)):
		out += str(v[i]) + " "
	print(out[0:len(out) - 1])

def verifica(v):
	for i in range(len(v) - 1):
		if v[i] < v[i + 1]:
			return False
	return True

def reverse(v, j):
	x = 1
	for i in range(j, len(v) - (len(v[j:len(v)]))//2):
		aux = v[len(v) - x]
		v[len(v) - x] = v[i]
		v[i] = aux
		x += 1

def solucion(v, i, out):
	if i != len(v):
		if not verifica(v):
			my = -1
			pmy = -1
			for j in range(i, len(v)):
				if my < v[j]:
					my = v[j]
					pmy = j
			
			if pmy != i:
				if pmy != len(v) - 1:
					reverse(v, pmy)
					out += str(pmy + 1) + " "
				reverse(v, i)
				out += str(i + 1) + " "
		solucion(v, i + 1, out)
	else:
		out += "0"
		print(out)

def sol():
	v = list(map(int, input().split()))
	aux = v
	v = v[::-1]	
	mostrar(aux)
	solucion(v, 0, "")

while True:
	try:
		sol()
	except EOFError:
		break