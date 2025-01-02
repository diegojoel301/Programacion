scad = input()

cad = input()

v = list()

for i in range(len(cad)):
	if cad[i:len(scad) + i] == scad:
		v.append(i)

out = str()

for i in v:
	out += str(i) + " "
print(out[0:len(out) - 1])
