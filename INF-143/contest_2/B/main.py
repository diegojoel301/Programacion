import math as m

def is_prime(n):
    prime_flag = 0
 
    if(n > 1):
        for i in range(2, int(m.sqrt(n)) + 1):
            if (n % i == 0):
                prime_flag = 1
                break
        if (prime_flag == 0):
            return True
        else:
            return False
    else:
        return False

N = int(input())

for _ in range(N):
    v = input()
    n = len(v)
    primes = list()

    for i in range(1, 6):
        for j in range(0, 1 + (n - i)):
            if(is_prime(int(v[j: j + i]))):
                primes.append(int(v[j: j + i]))

    primes = set(primes)

    print(len(primes))
