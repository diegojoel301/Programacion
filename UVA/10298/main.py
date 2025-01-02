from sys import stdin, stdout

while True:
	cad = input()

	if cad == ".":
		break

	my = -1

	for i in range(1, len(cad)):
		scad = cad[0:i]
		longitud = len(scad)
		n = len(cad) // len(scad)

		if cad == scad * n:
			if n > my:
				my = n

	if my == -1:
		print(1)
	else:
		print(my)
