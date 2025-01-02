def sol():
	cad1 = input()
	cad2 = input()

	res = sorted(set("abcdefghijklmnopqrstuvwxyz"))

	out = sorted(set(cad1+cad2))

	if res == out:
		print("Correcto")
	else:
		print("Incorrecto")
	
while True:
	try:
		sol()
	except EOFError:
		break