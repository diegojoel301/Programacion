#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> ac(n + 1);

	for(int i = 1; i <= n; i++) cin >> ac[i];

	// O(n ^ 2)
	//acumulada, volvemos nuestro vector a uno de acumulada que nos ayudara
	for(int i = 1; i <= n; i++) ac[i] += ac[i - 1];
	for(auto d: ac) cout << d << " "; cout << "\n";

	int mini = ac[0]; // 0

	int ans = -1e9; 

	for(int i = 1; i <= n; i++)
	{
		ans = max(ans, ac[i] - mini);
		mini = min(mini, ac[i]);
	}

	cout << ans << "\n";

	return 0;
}