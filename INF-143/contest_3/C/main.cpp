#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, k;

	cin >> t;

	while(t--)
	{
		cin >> n >> k;

		if(k > n / 2)
			cout << ((n - k + 1) / 2) + 1 << "\n";
		else
			cout << (k / 2) + 1 << "\n";
	}
	return 0;
}