#include<bits/stdc++.h>

using namespace std;

int N, C;

bool f(vector<int> &v, int x)
{
	int cnt = 1, p = 0;

	for(int i = 1; i < N; i++)
	{
		if(v[i] - v[p] >= x)
		{
			cnt++;
			p = i;
		}
	}

	if(cnt >= C)
		return true;
	return false;

}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		cin >> N >> C;

		vector<int> v(N);

		for(int i = 0; i < N; i++)
			cin >> v[i];

		sort(v.begin(), v.end()); //ordenado ascendentement

		int low = 0, high = v[N - 1];

		while(high - low > 1)
		{
			int mid = (high + low) / 2;

			if(f(v, mid))
				low = mid;
			else
				high = mid;
		}
		cout << low << "\n";
	}
	return 0;
}