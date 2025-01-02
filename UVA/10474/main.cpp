#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N = -1, Q = -1, c = 1, ans;

	while(N != 0 and Q != 0)
	{
		cin >> N >> Q;

		if(N == 0 and Q == 0)
			break;
		int v[N];

		for(int i = 0; i < N; i++)
			cin >> v[i];

		cout << "CASE# " << c << ":\n";

		for(int i = 0, query; i < Q; i++)
		{
			cin >> query;
			ans = 0;

			bool found = false;

			for(int j = 0; j < N; j++)
			{
				if(v[j] < query) ans++;

				if(v[j] == query) found = true;
			}

			if(found)
				cout << query << " found at " << ans << "\n";
			else
				cout << query << " not found\n";
		}
		c++;
	}
	return 0;
}