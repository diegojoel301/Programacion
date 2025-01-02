#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x, ans = 0;

	cin >> n;

	while(n--)
	{
		cin >> x;

		if(x >= 10)
			ans += x - 10;
	}

	cout << ans;

	return 0;
}