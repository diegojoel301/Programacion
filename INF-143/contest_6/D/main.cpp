#include<bits/stdc++.h>

using namespace std;

int f(vector<int> v, int i, int j)
{
	return abs(v[i] - v[j]);
}

int main()
{
	freopen("input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, ans;
	cin >> t;

	while(t--)
	{
		vector<int> v;
		cin >> n;

		for(int i = 0, value; i < n; i++)
		{
			cin >> value;
			v.push_back(value);
		}
		sort(v.begin(), v.end());
		
		/*
		int ans = 9999;

		for(int i = 0; i < v.size() - 1; i++)
		{
			if(ans > abs(v[i] - v[i + 1]))
				ans = abs(v[i] - v[i + 1]);
		}	
		cout << ans << "\n";*/

		int low = 0, high = v.size() - 1, ans = 9999, mid;

		while(high - low > 1)
		{
			mid = (high + low) / 2;

			if(f(v, mid, mid + 1) < ans)
			{
				ans = f(v, mid, mid + 1);
				low = mid;	
			}
			else
				high = mid;
		}

		cout << f(v, low, low + 1) << "\n";

	}

	return 0;
}