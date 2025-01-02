#include<bits/stdc++.h>

using namespace std;

long long int f(long long int n)
{
	return n * (n + 1) / 2;
}

int main()
{
	double x;

	cin >> x;

	double r1 = (-1 + sqrt(1 + (8 * (x - 1)))) / 2;
	long long int r2 = (-1 + sqrt(1 + (8 * (x - 1)))) / 2;

	if(r1 != r2)
	{
		long long int low = 1, high = 2 * x, mid;

		while(high - low > 1)
		{
			mid = (high + low) / 2;
			if(mid <= (2 * ((long long int)x - 1)) / (mid + 1))
				low = mid;
			else
				high = mid;
		}
		cout << to_string((long long int)x - f(low)) << "\n";
	}
	else
		cout << "1\n";	
	return 0;
}