#include<bits/stdc++.h>
#define MAX 100005
using namespace std;

bool prime[MAX];
vector<long long> primes;

void criba()
{	
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;

	for(int p = 2; p * p <= MAX; p++)
	{
		if(prime[p] == true)
		{
			for(int i = p * 2; i <= MAX; i += p)
				prime[i] = false;
		}
	}

	for(int i = 2; i <= MAX; i++)
	{
		if(prime[i])
			primes.push_back(i);
	}
}

int cum_sum(int n)
{
	int p = 0, auxp, s, c = 0;
	bool flag;

	while(primes[p] <= n)
	{
		auxp = p;
		flag = true;
		s = 0;

		while(auxp != -1 and flag)
		{
			s = s + primes[auxp];
			auxp--;
			if(s > n)
				flag = false;
			if(s == n)
			{
				flag = false;
				c++;
			}
		}
		p++;
	}
	return c;
}

int main()
{
	criba();
	int n;
	
	while(cin >> n)
		cout << cum_sum(n) << "\n";
	
	return 0;
}
