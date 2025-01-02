#include<bits/stdc++.h>

using namespace std;

long long int f(vector<long long int> v, int distance)
{
	long long int c = 1, value = v[0];

	for(int i = 1; i < v.size(); i++)
	{
		if(abs(value - v[i]) >= distance)
		{
			//cout << value << " " << v[i] << "\n";
			value = v[i];
			c++;
		}	
	}

	return c;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);

	int n, c, t;

	cin >> t;

	while(t--)
	{
		cin >> n >> c;
		vector<long long int> v(n);

		for(int i = 0; i < n; i++) cin >> v[i];

		sort(v.begin(), v.end());

		long long int low = 0, high = 1e9, mid;

		while(high - low > 1)
		{
			mid = (high + low) / 2;

			if(f(v, mid) >= c)
				low = mid;
			else
				high = mid;
		}

		cout << low << "\n";

	}

	return 0;
}