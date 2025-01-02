#include<bits/stdc++.h>

using namespace std;

long long int f(double n, long long int sum, long long int x)
{
	return sum - ((n + 1 - ceil(n / 2)) * x);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	double n;
	long long int s;

	cin >> t;

	while(t--)
	{
		cin >> n >> s;

		if(n == 1)
			cout << s << "\n";
		else if(s == 1)
			cout << "0\n";
		else
		{
			long long int low = 0, high = 1e10, mid;

			while(high - low > 1) 
			{
				mid = (high + low) / 2;
				if(f(n, s, mid) >= 0)
					low = mid;
				else
					high = mid;
			}

			if(f(n, s, low) >= 0 == f(n, s, high) >= 0)
				cout << max(low, high) << "\n";
			else if(f(n, s, low) >= 0 and not f(n, s, high) >= 0)
				cout << low << "\n";
			else if(f(n, s, high) >= 0 and not f(n, s, low) >= 0)
				cout << high << "\n";	
		}
	}

	return 0;
}