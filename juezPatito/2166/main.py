def SieveOfEratosthenes(n, prime):
    p = 2

    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * p, n+1, p):
                prime[i] = False
        p += 1

    prime[1] = prime[0] = False

prime = [True for i in range(10001)]

SieveOfEratosthenes(10000, prime)

ac = list()

S = input()
C = input()
c = 0

cad = str()

for elem in S:
    c += 1

    if prime[c] and not c in ac:
        ac.append(c)
        cad += C
        c = 0
    else:
        cad += elem

print(cad)
