import sys

def f(x):
	if x == "A" or x == "B" or x == "C":
		x = "2"
	elif x == "D" or x == "E" or x == "F":
		x = "3"
	elif x == "G" or x == "H" or x == "I":
		x = "4"
	elif x == "J" or x == "K" or x == "L":
		x = "5"
	elif x == "M" or x == "N" or x == "O":
		x = "6"
	elif x == "P" or x == "R" or x == "S":
		x = "7"
	elif x == "T" or x == "U" or x == "V":
		x = "8"
	elif x == "W" or x == "X" or x == "Y":
		x = "9"

	return x

def t(x):
	cad = str()
	w = str()

	if "-" in x:
		cad = x.split('-')
	else:
		cad = x

	cad = "".join(cad)

	for i in cad:
		w += f(i)

	return w[0:3] + "-" + w[3:len(w)]

sys.stdin = open("input.txt", "r")

d = dict()

while True:
	try:
		x = t(input())

		if x not in d.keys():
			d[x] = 1
		else:
			d[x] += 1
	except EOFError:
		break

v = list()

for x, y in d.items():
	if y > 1:
		v.append((x, y))
if len(v) >= 1:
	v.sort()
	for x, y in v:
		print(x, y)
else:
	print("Sin duplicados")
