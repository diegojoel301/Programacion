pelotas = [int(input()) for x in range(int(input()))]

pares = [x for x in pelotas if x % 2 == 0]
impares = [x for x in pelotas if x % 2 != 0]

pares.sort()
impares.sort(reverse = True)

for i in pares: print(i)
for i in impares: print(i)