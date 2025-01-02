#include<bits/stdc++.h>

using namespace std;

const long long n = 50000;

long long primos[100000];
long long nro = 0;
bool prime[n + 1];

void criba()
{
	prime[0] = true;
	prime[1] = true;

	for(long long i = 2; i <= n; i++)
	{
		if(not prime[i])
		{
			primos[nro++] = i;
			for(long long j = i * i; j <= n; j += i)
				prime[j] = true;
		}
	}

}

void sol(long long N)
{	
	long long salida[100], pos = 0;

	if(N < 0)
	{
		salida[pos++] = -1;
		N = abs(N);
	}

	for(long long int i = 0; i < nro; i++)
	{
		if(N == 1)
			break;
		while(N % primos[i] == 0)
		{
			salida[pos++] = primos[i];
			N /= primos[i];
		}
	}

	if(N > 1)
		salida[pos++] = N;
	
	for(int i = 0; i < pos - 1; i++)
		cout << salida[i] << " x ";
	cout << salida[pos - 1] << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	criba();

	long long x;

	while(true)
	{
		cin >> x;

		if(x == 0)
			break;
		cout << x << " = ";
		sol(x);
		
	}

	return 0;
}