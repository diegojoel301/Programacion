#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;

	cin >> n >> m;

	vector<int> v(n), k(m);

	for(int i = 0; i < n; i++) cin >> v[i];

	for(int i = 0; i < m; i++) cin >> k[i];

	int ans[m];
	int pos = 0;

	sort(v.begin(), v.end());

	for(int i = 0; i < n; i++)
	{
		int low = -1, high = m;

		while(high - low > 1)
		{
			int mid = (low + high) / 2;

			if(v[mid] <= k[i])
				low = mid;
			else
				high = mid;
		}

		ans[pos++] = low + 1;
	}

	for(int i = 0; i < m; i++)
		cout << ans[i] << " ";


	return 0;
}