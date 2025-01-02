"""
import sys

for linea in sys.stdin:
	linea = linea.strip()
	pila = list()
	for i in linea:
		if i.isdigit(): pila.append(int(i))
		elif i == '+':
			num1 = pila.pop()
			num2 = pila.pop()
			pila.append(num1 + num2)
		elif i == '*':
			num1 = pila.pop()
			num2 = pila.pop()
			pila.append(num1 * num2)

	print(pila.pop())
"""
# moificacion de -* del lic

linea = "2-3+"
pila = list()
for i in linea:
	if i.isdigit(): pila.append(int(i))
	elif i == '+':
		num1 = pila.pop()
		num2 = pila.pop()
		pila.append(num1 + num2)
	elif i == '*':
		num1 = pila.pop()
		num2 = pila.pop()
		pila.append(num1 * num2)
	elif i == '-':
		num1 = pila.pop()
		pila.append(-num1)
	elif i == '/':
		num1 = pila.pop()
		num2 = pila.pop()
		pila.append(num1 / num2)
print(pila.pop())