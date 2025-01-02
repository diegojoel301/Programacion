#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, k;

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> n >> k;
		n = n + 2;
		k++;

		cout << (k * n * (n - 1)) / 2 << "\n";
	}

	return 0;
}