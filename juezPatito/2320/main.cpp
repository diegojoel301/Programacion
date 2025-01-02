#include<bits/stdc++.h>

using namespace std;

int f(int x)
{
	if(x > 0)
		return ((x % 10) + f(x / 10)) % 9;
	else
		return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	while(n--)
	{
		int x, g, k, ans = 0;

		cin >> x >> k;

		k++;

		while(k--)
		{
			g = f(x);
			ans += g * g;
			x = g * g;
		}

		cout << ans << "\n";
	}

	return 0;
}