n = int(input())

vv = list(input().split())

v = list()

for i in vv:
	v.append(int(i))

a = 0
b = 0

v.sort()

print(v)

for i in range(len(v)):

	if i % 2 == 0:
		a += v[i]
	else:
		b += v[i]


print(a)
print(b)
