#include<bits/stdc++.h>

using namespace std;

int sump(int N)
{
	int primes[N + 1] = {0};

	for(int i = 2; i <= N; i++)
	{
		if(not primes[i])
		{
			for(int j = i; j <= N; j += i)
				primes[j] += i;
		}
	}
	return primes[N];
}

bool verifica(int a)
{
	return sump(a) == sump(a + 1);
}

int main()
{
	
	int a, b;
	while(cin >> a >> b)
	{
		for(int i = a; i <= b; i++)
		{
			if(verifica(i))
				cout << i << " " << i + 1 << "\n";
		}
	}

	return 0;
}