#include<bits/stdc++.h>

using namespace std;

long long int pos(long long int x, long long int n)
{
	return x - (x / n);
}

int main()
{
	int t;
	long long int n, k;
	cin >> t;

	while(t--)
	{
		cin >> n >> k;
		
		long long int low = 1, high = 100000000000000, mid;

		while(high - low > 1)
		{
			mid = (high + low) / 2;

			if(pos(mid, n) <= k)
				low = mid;
			else
				high = mid;
		}

		if(low % n == 0)
			cout << low - 1 << "\n";
		else
			cout << low << "\n";
	}

	return 0;
}