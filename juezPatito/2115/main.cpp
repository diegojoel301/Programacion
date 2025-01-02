#include<bits/stdc++.h>
#define M 100001

using namespace std;

bool prime[M];
vector<int> v(M);

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
	prime[1] = false;
}

void gen()
{
	int s = 0;

	for(int i = 1; i < M; i++)
	{
		if(prime[i])
			s += i;
		v[i] = s;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q, L, R;
	criba();
	gen();
	
	cin >> q;

	while(q--)
	{
		cin >> L >> R;
		
		if(prime[L])
			cout << v[R] - v[L - 1] << "\n";
		else
			cout << v[R] - v[L] << "\n";
	}

	return 0;
}