def ex_rapida(a, b):
	if b % 2 == 0:
		return ex_rapida(a, b // 2) ** 2
	else:
		return a * ex_rapida(a, b // 2) ** 2

print(ex_rapida(2, 4))