#include<bits/stdc++.h>

using namespace std;

const int e = 5000;

int coing[4];

int dp[4000 + 10];

int main()
{
	memset(dp, -1, sizeof (dp));

	int n, a, b, c;

	cin >> n >> a >> b >> c;

	coing[0] = a;
	coing[1] = b;
	coing[2] = c;

	dp[0] = 0;

	for(int i = 1; i <= n; i++)
	{
		dp[i] = -1e9;

		for(int j = 0; j < 3; j++)
		{
			if(i >= coing[j])
				dp[i] = max(dp[i], 1 + dp[1 - coing[j]]);
		}

	}

	cout << dp[n] << "\n";

	return 0;
}