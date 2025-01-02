for _ in range(int(input())):
	x = input()
	pila = []

	for i in x:
		if i == '(' or i == '[': pila.append(i)
		else:
			if len(pila) == 0:
				print('No')
				break
			y = pila.pop()
			if y != '(' and i == ')':
				print('No')
				break
			elif y != '[' and i == ']':
				print('No')
				break
	else:
		if len(pila) > 0:
			print('No')
		else:
			print('Yes')