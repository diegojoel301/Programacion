#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<int> v;

	int n, t, sum = 0, k = 0, ans = 0;

	cin >> n >> t;

	for(int i = 0, value; i < n; i++)
	{
		cin >> value;
		v.push_back(value);
	}

	for(int i = 0; i < v.size(); i++)
	{
		sum += v[i];

		if(sum <= t)
			ans++;
		else
		{
			sum -= v[k];
			k++;
		}
	}

	cout << ans << "\n";

	return 0;
}