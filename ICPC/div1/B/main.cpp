#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, ans;

	cin >> n;

	for(int i = 1, x; i <= n; i++)
	{
		cin >> x;
		ans += i * x;
	}
	cout << ans;

}