#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, k; cin >> n;

	vector<int> v(n);

	for(int i = 0; i < n; i++) cin >> v[i];

	sort(v.begin(), v.end());

	int q; cin >> q;

	while(q--)
	{
		cin >> k;
		int low = 0, high = n;

		while(high - low > 1)
		{
			int mid = (high + low) / 2;

			if(v[mid] <= k)
				low = mid;
			else
				high = mid;
		}
		if(v[low] == k)
			cout << "Si contiene\n";
		else
			cout << "No contiene\n";
	}

	return 0;
}