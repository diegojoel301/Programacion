#include<bits/stdc++.h>
#define M 10000000
using namespace std;

bool prime[M + 1];

void criba()
{
	memset(prime, true, sizeof(prime));

	for(int p = 2; p * p <= M; p++)
	{
		if(prime[p] == true)
		{
			for(int i = p * 2; i <= M; i += p)
				prime[i] = false;
		}
	}
	prime[0] = prime[1] = false;
}

int derecha(int n)
{
	int c = 0;

	while(not prime[n])
	{
		n++;
		c++;
	}
	return c;
}

int izquierda(int n)
{
	int c = 0;
	while(not prime[n])
	{
		n--;
		c++;
	}

	return c;
}

int main()
{
	int n, x, izq, der;
	memset(prime, true, sizeof(prime));
	criba();

	cin >> n;

	while(n--)
	{
		cin >> x;
		izq = izquierda(x);
		der = derecha(x);

		cout << min(izq, der) << "\n";
	}

	return 0;
}