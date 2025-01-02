def f(item):
	if item[0] == item[1]:
		return 0
	return 1

#a = [3, 3, 4, 8, 1, 5, 2, 3, 8, 9]
a = [(7, 2), (6, 5), (1, 1)]
print(a)
a.sort()
print(a)
a.sort(reverse = True) # alrevez
print(a)
a.sort(key=f) # aca definimos una funcion para ordenar un vector
print(a)