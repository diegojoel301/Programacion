#include<bits/stdc++.h>

using namespace std;

vector<int> primes;

void criba(int n)
{
	bool prime[n + 1];

	memset(prime, true, sizeof(prime));

	for(int p = 2; p * p <= n; p++)
	{
		if(prime[p] == true)
		{
			for(int i = p * 2; i <= n; i += p)
				prime[i] = false;
		}
	}
	prime[0] = prime[1] = false;

	for(int p = 2; p <= n; p++)
		if(prime[p])
			primes.push_back(p);

}

void simplificacion(int &a, int &b)
{
	for(int i = 0; i < primes.size(); i++)
	{
		while(a % primes[i] == 0 and b % primes[i] == 0)
		{
			a /= primes[i];
			b /= primes[i];
		}
	}
}

int main()
{

	criba(10000);

	int a, b, c, d, num, den;

	cin >> a >> b >> c >> d;
	num = (a * d) + (b * c);
	den = b * d;
	simplificacion(num, den);
	cout << num << " " << den << "\n";

	return 0;
}