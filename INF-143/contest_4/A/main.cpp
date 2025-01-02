#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;

	while(cin >> N)
	{

		vector<pair<int, int>> v(N);

		for(int i = 0; i < N; i++) cin >> v[i].first;

		for(int i = 0; i < N; i++) cin >> v[i].second;

		sort(v.begin(), v.end());

		for(int i = 1, a, b, x, y; i < N; i++)
		{
			a = v[i - 1].first; b = v[i - 1].second;
			x = v[i].first; y = v[i].second;

			if(x <= b and y <= b)
			{
				v[i - 1].first = -1;
				v[i - 1].second = -1;

				v[i].first = a;
				v[i].second = b;
			}
			else if(x <= b)
			{
				v[i - 1].first = -1;
				v[i - 1].second = -1;

				v[i].first = a;
			}
		}

		int sum = 0;

		for(int i = 0; i < N; i++)
		{
			if(v[i].first != -1 and v[i].second != -1)
				sum += v[i].second - v[i].first;
		}

		cout << sum << "\n";
	}

	return 0;
}