def f(x):
	ans = 0
	val = x

	if x == 0:
		return 1

	if(x == 1):
		return 3

	N = 4294967296

	#for(int i = x - 1; i >= 1; i--)
	for i in range(x - 1, 0, - 1):
		ans = ((ans % N) + (val % N)) % N;
		val = ((val % N) * (i % N)) % N; 

	return ((ans % N) + 1 + (val % N)) % N;

entrada = input().split()

print(f(int(entrada[0])))
