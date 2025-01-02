#include<bits/stdc++.h>

using namespace std;

const int e = 5000;

int coing[4];
int dp[4000 + 10];

int f(int x)
{
	if(x == 0)
		return 0;
	if(dp[x] != -1)
		return dp[x];
	dp[x] = -1e9;

	for(int i = 0; i < 3; i++)
	{
		if(x >= coing[i])
			dp[x] = max(dp[x], 1 + f(x - coing[i]));
	}
	return dp[x];
}

int main()
{
	memset(dp, -1, sizeof dp);

	int n, a, b, c;
	cin >> a >> b >> c;

	coing[0] = a;
	coing[1] = b;
	coing[2] = c;

	cout << f(n) << "\n";


	return 0;
}