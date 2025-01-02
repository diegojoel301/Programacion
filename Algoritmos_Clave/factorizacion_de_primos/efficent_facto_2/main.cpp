#include<bits/stdc++.h>

using namespace std;

vector<int> primos;

void criba(int n)
{
	bool prime[n + 1];

	memset(prime, true, sizeof(prime));

	for(int p = 2; p * p <= n; p++)
	{
		if(prime[p] == true)
		{
			primos.push_back(p);
			for(int i = p * 2; i <= n; i += p)
				prime[i] = false;
		}
	}

}

void sol(long long int N)
{
	vector<long long int> sol_primos;
	
	for(int i = 0; i < primos.size(); i++)
	{
		while(N % primos[i] == 0)
		{
			cout << primos[i] << "\n";
			sol_primos.push_back(primos[i]);
			N /= primos[i];
		}
	}

	if(N > 1)
	{
		cout << N << "\n";
		sol_primos.push_back(N);
	}
}

int main()
{
	criba(100000);
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);

	int x;

	while(true)
	{
		cin >> x;

		if(x == 0)
			break;

		//cout << sol(x) << "\n";
		sol(x);
		
	}

	return 0;
}
