#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		vector<int> v(n);

		for(int i = 0; i < n; i++) cin >> v[i];

		int dinero; cin >> dinero;

		sort(v.begin(), v.end());

		int minimo = 1e9, ansx = 0, ansy = 0;

		for(int i = 0; i < n; i++)
		{
			int need = dinero - v[i], low = i + 1, high = n;

			while(high - low > 1)
			{
				int mid = (high + low) / 2;

				if(v[mid] <= need)
					low = mid;
				else
					high = mid;
			}

			if(v[i] + v[low] == dinero)
			{
				if(abs(v[i] - v[low]) <= minimo)
				{
					minimo = abs(v[i] - v[low]);
					ansx = v[i];
					ansy = v[low];
				}
			}
		}

		cout << "Peter should buy books whose prices are " << min(ansx, ansy) << " and " << max(ansx, ansy) << ".\n\n";
	}
	return 0;
}