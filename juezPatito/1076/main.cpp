#include<bits/stdc++.h>

using namespace std;

vector<int> dp(1002);

void minOp()
{
	for(int i = 2; i <= 1001; i++)
	{
		dp[i] = dp[i - 1] + 1;

		if(i % 2 == 0)
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		if(i % 3 == 0)
			dp[i] = min(dp[i / 3] + 1, dp[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, n;
	minOp();

	cin >> T;
	
	while(T--)
	{
		cin >> n;

		cout << dp[n] << "\n";
	}
	return 0;
}