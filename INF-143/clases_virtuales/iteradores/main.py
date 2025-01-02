mi_iterador = iter([1, 2, 4, 5])

a = list(iter(range(5)))

"""
	Hash Tables: define un espacio de memoria donde atraves de una formula encuentra la posicion donde esta almacenado
	Demora O(1) en encontrar la posicion
	El problema es cuando hay colisiones
"""

"""
	n cuando lo hago crecer a tamaño n + 1
	hay q hacer una copia a un espacio mas grande
	el nuevo tamaño es de n*2
	n*4 etc
	en promedio los datos se mueven O(log(n))
"""

"""
	Cola de prioridad estructura HEAP (monton)
	permite obtener el elemento de mas prioridad en O(1)
"""

import heapq

datos = [99, 33, 1, 8, 2, 5]
heapq.heapify(datos) # para transformar una lista a una cola de prioridad
"""
heapq.heappush(datos, 2)
heapq.heappush(datos, 3)
heapq.heappush(datos, 1)
heapq.heappush(datos, 4)
"""
while datos:
	print(heapq.heappop(datos), end = " ")

from queue import PriorityQueue

l = PriorityQueue()

l.put(5)
l.put(3)
l.put(5)
l.put(2)
l.put(5)
l.put(6)
print()
while not l.empty():
	print(l.get(), end = " ")
