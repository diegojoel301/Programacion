#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	
	string s; cin >> s;

	vector<int> a(n);

	for(int i = 0; i < n; i++)
		a[i] = s[i] - '0';

	vector<int> ans(n, 10);
	for(int i = 0; i < n; i++)
	{
		vector<int> curr(n);

		int m = (10 - a[i]) % 10;

		for(int j = 0; j < n; j++)
			curr[j] = (a[(j + i) % n] + m) % 10;

		ans = min(ans, curr);
	}
	
	for(int i = 0; i < n; i++)
		cout << ans[i];

	cout << "\n";

	return 0;
}