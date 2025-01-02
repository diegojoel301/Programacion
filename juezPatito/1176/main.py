from sys import stdin

for linea in stdin:
	personas, limite, promedio = map(int, linea.split())

	c = 0

	for i in range(personas):
		numero, edad = stdin.readline().split()
		numero = int(numero) if int(numero) > c else c
		c = numero + promedio

		if c <= limite:
			print(c)
		else:
			print("Mil disculpas, regrese mañana")