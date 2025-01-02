"""
a = [8, 4, 3, 4, 4, 4, 4, 5, 1, 1, 2, 9, 1, 7, 99, 5, 5, 4]


Ordenacion lineal O(n) < O(nlog(n))
Requisito conocer la posicion donde debe estar cada elemento
por anticipado.
Numero maximo(a) = 9

max_value = 99
v = [0]*(max_value + 1)

for i in a:
	v[i] += 1
print(v)
print(*a)

maximo = p = 0 # maximo cantidad de repeticiones

for i in range(len(a) + 1):
	if v[i] == 1:
		print(i, end = " ")

for i in range(len(v)):
	#for j in range(v[i]): # al retirar este for podremos tener nuestro conjunto sin duplicados O(n), antes cambiar esta linea por if v[i] == 1:
	if v[i] > maximo:
		maximo = v[i]
		p = i
print(i, p)"""

a = "wuyastuwxua"

# Decir cuantos caracteres sin repetidos hay

v = [0] * 26 # creamos el espacio de repeticiones de los elementos de caracteres

for i in a:
	v[ord(i) - ord('a')] = 1 # llenamos el vector de incidencias

c = sum(v)
print(c)

print(c)