#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);

	int n;

	cin >> n;

	int mat[n][3], dp[n][3];

	memset(mat, 0, sizeof mat);
	memset(dp, 0, sizeof dp);

	for(int i = 0; i < n; i++)
		cin >> mat[i][0] >> mat[i][1] >> mat[i][2];

	dp[0][0] = mat[0][0];
	dp[0][1] = mat[0][1];
	dp[0][2] = mat[0][2];
	
	for(int i = 1; i < n; i++)
	{
		int val;
		// para la columna 0

		val = max(dp[i - 1][1], dp[i - 1][2]);

		dp[i][0] = mat[i][0] + val;

		// para la columna 1

		val = max(dp[i - 1][0], dp[i - 1][2]);

		dp[i][1] = mat[i][1] + val;

		// para la columna 2

		val = max(dp[i - 1][0], dp[i - 1][1]);

		dp[i][2] = mat[i][2] + val;

	}
	/*
	for(int i = 0; i < n; i++)
		cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << "\n";
	*/
	cout << max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
	return 0;
}