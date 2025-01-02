while True:
	try:
		n = int(input())
		x = int(str(bin(n))[2::][::-1], 2)
		print(n - x)
	except EOFError:
		break