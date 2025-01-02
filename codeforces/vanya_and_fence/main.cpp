#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, h, ans = 0;

	cin >> n >> h;

	for(int i = 0, value; i < n; i++)
	{
		cin >> value;

		if(value <= h)
			ans++;
		else
			ans += 2;
	}

	cout << ans;

	return 0;
}