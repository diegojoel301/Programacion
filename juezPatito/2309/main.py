def A(x):
	if x > 0:
		return (x % 10) + A(x // 10)
	else:
		return 0

v = list()
ac = list()

def gen():
	v.append(0)
	ac.append(0)

	for i in range(1, 10000005):
		ac.append(0)
		v.append(A(i))

	for i in range(1, 10000000):
		if v[i + 1] < v[i]:
			ac[i] = 1 + ac[i - 1]
		else:
			ac[i] = ac[i - 1]

gen()

for _ in range(int(input())):
	print(ac[int(input())])