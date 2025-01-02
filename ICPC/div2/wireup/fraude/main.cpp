#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, cnt;

	cin >> t;

	while(t--)
	{
		cin >> n;
		cnt = 0;

		vector<int> v(n);

		for(int i = 0; i < n; i++) cin >> v[i];

		for(int i = 0; i < n; i++)
		{
			bool flag = false;

			for(int j = i + 1; j < n; j++)
			{
				if(v[i] < v[j])
				{
					flag = true;
					break;
				}
			}

			if(flag)
				cnt++;
		}

		cout << cnt << "\n";
	}

	return 0;
}