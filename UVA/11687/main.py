import math as m
import sys

def f(n):
	if n > 0:
		return int(m.log10(n)) + 1
	else:
		return 1

while True:
	cad = sys.stdin.readline()

	if cad == "END\n":
		break
	elif cad == "1":
		sys.stdout.write(1 + "\n")
	else:
		n = int(cad)

		c = 1

		while f(n) != 1:
			c += 1
			n = f(n)

		c = str(c + 1)

		sys.stdout.write(c + "\n")
	