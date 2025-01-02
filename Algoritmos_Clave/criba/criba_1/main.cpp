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

	for(int p = 2; p <= n; p++)
		if(prime[p])
			primes.push_back(p);

}

int main()
{
	criba(10);

	for(int i = 0; i < primes.size(); i++)
		cout << primes[i] << " ";

	cout << "\n";

	return 0;
}