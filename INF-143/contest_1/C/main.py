while True:
	try:
		a, b = map(int, input().split())

		n1 = int(bin(a), 2)
		n2 = int(bin(b), 2)

		bit_or = n1 | n2
		bit_and = n1 & n2
		bit_res = n1 & ~n2

		print(bit_or, bit_and, bit_res)

	except EOFError:
		break