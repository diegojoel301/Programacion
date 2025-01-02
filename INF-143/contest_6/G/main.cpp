#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	vector<pair<int, int>> sol;

	for(int i = 0, value; i < n; i++)
	{
		cin >> value;
		v.push_back(value);
	}

	for(int i = 0; i < n - 1; i++)
	{
		if(v[i] % 2 != 0 and v[i + 1] % 2 != 0)
		{
			if(v[i] + 2 == v[i + 1])
				sol.push_back(make_pair(v[i], v[i + 1]));
		}
	}

	for(int i = 0; i < sol.size(); i++)
		cout << sol[i].first << " " << sol[i].second << "\n";

	return 0;
}