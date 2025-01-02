#include<bits/stdc++.h>

using namespace std;

long long int n, m, k;

bool f(long long int mid)
{
	long long sum = 0;

	if(k - (mid - 1) > 1)
	{
		sum += k - (mid - 1) - 1;
		sum += (1 + mid)*mid/2;
	}

	if(k - (mid - 1) == 1)
		sum += (1 + k)*k/2;

	if(k - (mid - 1) < 1)
		sum += (mid - (k - 1) + mid)*k/2;
	if(k + (mid - 1) < n)
	{
		sum += n-(k + (mid - 1));
		sum += (1 + mid) * mid/2;
	}

	if(k + (mid - 1) == n)
		sum += (1 + mid)*mid/2;

	if(k + (mid - 1) > n)
		sum += (mid - (n - k) + mid)*(n - k + 1)/2;

	return sum - mid <= m;

}

int main()
{
	
	/*
	while(cin >> n >> m >> k)
	{
		long long int low = 1, high = m, mid, ans = 0;

		while(high - low >= 0)
		{
			mid = (high + low) / 2;

			if(f(mid))
			{
				ans = mid;
				low = mid + 1;
			}
			else
				high = mid - 1;
		}

		cout << ans << "\n";
	}
	*/

	n = 

	return 0;
}