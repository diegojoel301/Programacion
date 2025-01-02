from collections import Counter

def unique(v):
	print(*Counter(v))

entrada = list(input())
v = list()

for i in entrada:
	v.append(i)

unique(v)
