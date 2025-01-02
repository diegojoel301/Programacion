#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void sol()
{
	long long int N, val, i, ans = 1;

	cin >> N;

	for(i = 0; i < N; i++)
	{
		cin >> val;
		ans = ((ans % MOD) * ((val + 1) % MOD)) % MOD;
	}

	cout << ans - 1 << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;

	cin >> t;

	while(t--)
		sol();

	return 0;
}