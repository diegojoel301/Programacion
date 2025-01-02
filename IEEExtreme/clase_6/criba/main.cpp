#include<bits/stdc++.h>
#define ll long long 

using namespace std;

// Criba de Eratostenes O(N^2)

void criba1()
{
	int N = 100;
	vector<bool> primes(N, true);
	primes[0] = primes[1] = false;

	for(int i = 2; i < N; i++)
	{
		if(primes[i] == true) // i es primo, tachar los multiplos de i
		{
			for(int j = i + i; j < N; j += i)
				primes[j] = false;
		}
	}

	for(int i = 0; i < N; i++)
	{
		if(primes[i])
			cout << i << "\n";
	}
}

// Criba de Eratostenes O(N log (N)*log(N))

int main()
{
	int N = 100;
	vector<bool> primes(N, true);
	primes[0] = primes[1] = false;

	for(ll i = 4; i < N; i = i + 2)
		primes[i] = false;

	for(ll i = 2; i * i < N; i++) // hasta raiz deberiamos procesar esto
	{
		if(primes[i]) // i es primo, tachar los multiplos de i
		{
			for(ll j = i * i; j < N; j += i + i) // desde el cuadrado se tacha ya que los anteriores seran ya tachados
				primes[j] = false;
		}
	}

	for(int i = 0; i < N; i++)
	{
		if(primes[i])
			cout << i << "\n";
	}	

	return 0;
}