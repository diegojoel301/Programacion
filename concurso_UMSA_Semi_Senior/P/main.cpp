#include<bits/stdc++.h>

using namespace std;

int dig(int x)
{
	if(x > 0)
		return (x % 10) + dig(x / 10);
	else
		return 0;
}

int f(int x)
{
	if(x % 10 == x)
		return x;
	else
		return f(dig(x));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string n, ans;
	int k, x, t;

	cin >> t;

	while(t--)
	{
		cin >> n >> k;
		ans = "";

		for(int i = n.size() - 1; i > k - 2; i--)
		{
			x = stoi(n.substr(i - k + 1, k));

			ans = to_string(f(x)) + ans; 
		}

		cout << ans << "\n";
	}

	return 0;
}