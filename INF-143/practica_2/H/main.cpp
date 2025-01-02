#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;

	cin >> n;

	int k = 2;

	vector<int> v(n);
	
	for(int i = 0; i < n; i++)
		cin >> v[i];

	vector<int> dp(n + 20, INT_MAX);

	dp[0] = 0;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < i + k + 1; j++)
			dp[j] = min(dp[j], dp[i] + abs(v[i] - v[j]));
	}
	
	cout << dp[n - 1];
	
	return 0;
}