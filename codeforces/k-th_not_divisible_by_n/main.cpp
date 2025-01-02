#include<bits/stdc++.h>

using namespace std;

int n, k;

long long f(long long x)
{
	return x - (x / n); // cuantos no divisibles por n hay de 1 a x 
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		cin >> n >> k;
		long long low = 1, high = 2000000000;
		while(high - low > 1)
		{
			long long mid = (high + low) / 2;

			if(f(mid) <= k)
				low = mid;
			else
				high = mid;
		}
		if(low % n == 0)
			low -= 1;

		cout << low << "\n";
	}



	return 0;
}